function trapRainWater(heightMap) {
    const minHeap = [];
    function heapify(i) {
        let smallest = i;
        let left = 2 * i + 1;
        let right = left + 1;

        if (left < minHeap.length && minHeap[left][0] < minHeap[smallest][0]) smallest = left;
        if (right < minHeap.length && minHeap[right][0] < minHeap[smallest][0]) smallest = right;
        if (smallest != i) {
            [minHeap[i], minHeap[smallest]] = [minHeap[smallest], minHeap[i]];
            heapify(smallest);
        }
    }

    function extractMin() {
        if (minHeap.length == 0) return [];
        const min = minHeap[0];
        minHeap[0] = minHeap[minHeap.length - 1];
        minHeap.pop();
        heapify(0);
        return min;
    }
    function insertHeap(el) {
        minHeap.push(el);
        let i = minHeap.length - 1;
        let temp = Math.floor((i - 1) / 2);
        while (i !== 0 && minHeap[temp][0] > minHeap[i][0]) {
            [minHeap[i], minHeap[temp]] = [minHeap[temp], minHeap[i]];
            i = temp;
            temp = Math.floor((i - 1) / 2);
        }
    }
    const rs = heightMap.length;
    const cs = heightMap[0].length;

    const tracker = Array.from({ length: rs }, () => Array.from({ length: cs }, () => false));

    for (let i = 0; i < rs; i++) {
        for (let j = 0; j < cs; j++) {
            // Edgelords
            if (i == 0 || i == rs - 1 || j == 0 || j == cs - 1) {
                insertHeap([heightMap[i][j], i, j]);
                tracker[i][j] = true;
            }
        }
    }

    let ans = 0;
    const dirs = [-1, 0, 1, 0, -1];

    while (minHeap.length) {
        const [currentHeight, row, col] = extractMin();

        for (let i = 0; i < 4; i++) {
            const newRow = row + dirs[i];
            const newCol = col + dirs[i + 1];
            if (newRow + 1 && newRow < rs && newCol + 1 && newCol < cs && !tracker[newRow][newCol]) {
                ans += Math.max(0, currentHeight - heightMap[newRow][newCol]);
                tracker[newRow][newCol] = true;
                insertHeap([Math.max(heightMap[newRow][newCol], currentHeight), newRow, newCol]);
            }
        }
    }
    return ans;
}
