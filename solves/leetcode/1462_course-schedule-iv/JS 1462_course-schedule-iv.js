/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @param {number[][]} queries
 * @return {boolean[]}
 */
function checkIfPrerequisite(numCourses, prerequisites, queries) {
    const reqMat = Array.from({ length: numCourses }, () => Array.from({ length: numCourses }, () => false));
    const cor = Array.from({ length: numCourses }, () => []);
    const inD = Array.from({ length: numCourses }, () => 0);

    for (const [pre, cour] of prerequisites) {
        cor[pre].push(cour);
        inD[cour]++;
    }

    const queue = [];
    for (let course = 0; course < numCourses; course++) {
        if (inD[course] === 0) {
            queue.push(course);
        }
    }

    while (queue.length) {
        const curr = queue.shift();

        for (const nxt of cor[curr]) {
            reqMat[curr][nxt] = true;

            for (let preCourse = 0; preCourse < numCourses; ++preCourse) {
                reqMat[preCourse][nxt] ||= reqMat[preCourse][curr];
            }

            if (--inD[nxt] == 0) queue.push(nxt);
        }
    }
    return queries.map(([start, end]) => reqMat[start][end]);
}
