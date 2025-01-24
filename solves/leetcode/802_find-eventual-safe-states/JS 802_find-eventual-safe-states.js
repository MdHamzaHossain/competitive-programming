function dfs(node, tracker, graph) {
    if (tracker[node]) return tracker[node] === 2;

    tracker[node] = 1;
    for (const nxt of graph[node]) {
        if (!dfs(nxt, tracker, graph)) return false;
    }
    tracker[node] = 2;
    return true;
}
/**
 * @param {number[][]} graph
 * @return {number[]}
 */
function eventualSafeNodes(graph) {
    const len = graph.length;
    const tracker = new Array(len).fill(0);

    const res = [];
    for (let i = 0; i < len; ++i) {
        if (dfs(i, tracker, graph)) res.push(i);
    }
    return res;
}
