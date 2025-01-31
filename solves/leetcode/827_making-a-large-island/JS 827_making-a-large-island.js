function dfs(i, j, path, grid, tracker, n) {
    if (i < 0 || j < 0 || i >= n || j >= n || tracker[i][j] || grid[i][j] !== 1) return;
    tracker[i][j] = true;

    path.push([i, j]);

    dfs(i + 1, j, path, grid, tracker, n);
    dfs(i, j + 1, path, grid, tracker, n);
    dfs(i - 1, j, path, grid, tracker, n);
    dfs(i, j - 1, path, grid, tracker, n);
}

/**
 * @param {number[][]} grid
 * @return {number}
 */
function largestIsland(grid) {
    const n = grid.length;
    const tracker = Array.from({ length: n }, () => new Array(n).fill(false));
    const group = Array.from({ length: n }, () => new Array(n).fill(0));

    let groupId = 1;

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            const path = [];
            dfs(i, j, path, grid, tracker, n);
            if (path.length !== 0) {
                for (const [x, y] of path) {
                    group[x][y] = groupId;
                    grid[x][y] = path.length;
                }
                groupId++;
            }
        }
    }

    let mx = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 0) {
                let sum = 1;
                const uniqueGroups = new Set();
                if (i > 0 && !uniqueGroups.has(group[i - 1][j])) {
                    sum += grid[i - 1][j];
                    uniqueGroups.add(group[i - 1][j]);
                }
                if (i < n - 1 && !uniqueGroups.has(group[i + 1][j])) {
                    sum += grid[i + 1][j];
                    uniqueGroups.add(group[i + 1][j]);
                }
                if (j > 0 && !uniqueGroups.has(group[i][j - 1])) {
                    sum += grid[i][j - 1];
                    uniqueGroups.add(group[i][j - 1]);
                }
                if (j < n - 1 && !uniqueGroups.has(group[i][j + 1])) {
                    sum += grid[i][j + 1];
                }
                mx = Math.max(mx, sum);
            } else {
                mx = Math.max(mx, grid[i][j]);
            }
        }
    }
    return mx;
}
