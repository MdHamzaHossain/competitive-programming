function stringMatching(words) {
    return words.filter((a, ia) => words.find((b, ib) => b.includes(a) && ia !== ib));
}
