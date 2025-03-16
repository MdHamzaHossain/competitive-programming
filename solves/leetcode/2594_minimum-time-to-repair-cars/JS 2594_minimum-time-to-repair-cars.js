/**
 * @param {number[]} ranks
 * @param {number} cars
 * @return {number}
 */
function repairCars(ranks, carsToRepair) {
    let min = 0;
    let max = ranks[0] * carsToRepair * carsToRepair;

    while (min < max) {
        const mid = min + Math.floor((max - min) / 2);
        let tot = 0;

        for (const rank of ranks) {
            tot += Math.floor(Math.sqrt(mid / rank));
        }

        if (tot >= carsToRepair) {
            max = mid;
        } else {
            min = mid + 1;
        }
    }

    return min;
}
