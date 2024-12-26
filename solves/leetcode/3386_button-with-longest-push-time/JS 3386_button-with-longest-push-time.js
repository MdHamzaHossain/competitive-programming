function buttonWithLongestTime(events) {
    let prevValue = 0;
    let max = 0,
        maxInd;
    for (const [key, value] of events) {
        let x = value - prevValue;
        prevValue = value;
        if (x > max) {
            max = x;
            maxInd = key;
        } else if (x == max && maxInd > key) {
            maxInd = key;
        }
    }
    return maxInd;
}
