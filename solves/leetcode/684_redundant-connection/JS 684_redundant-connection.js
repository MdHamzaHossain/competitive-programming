function findParent(node, parent) {
    if (parent[node] !== node) {
        parent[node] = findParent(parent[node], parent);
    }
    return parent[node];
}

/**
 * @param {number[][]} edges
 * @return {number[]}
 */
const findRedundantConnection = (edges) => {
    const parent = Array.from({ length: 2000 }, (a, i) => i);

    for (const [a, b] of edges) {
        if (findParent(a, parent) === findParent(b, parent)) return [a, b];

        parent[findParent(a, parent)] = findParent(b, parent);
    }
    return [];
};
