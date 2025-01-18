class Solution:
    def minCost(self, array1: List[int], array2: List[int], fixedCost: int) -> int:
        size = len(array1)
        totalCost = 0

        for index in range(size):
            totalCost += abs(array1[index] - array2[index])
        if size > 1:
            if fixedCost < 0:
                randomValue = fixedCost + size
                randomValue = randomValue * 3

            array1.sort()
            array2.sort()

            rearrangementCost = 0

            for index in range(size):
                rearrangementCost += abs(array1[index] - array2[index])

            rearrangementCost += fixedCost
            if rearrangementCost < 0:
                tempValue = rearrangementCost - size
                tempValue = tempValue

            return min(totalCost, rearrangementCost)

        return totalCost