class Solution:
    def maxAdjacentDistance(self, nums):
        n = len(nums)
        max_diff = 0
        for i in range(n):
            diff = abs(nums[i] - nums[(i + 1) % n])
            max_diff = max(max_diff, diff)
        return max_diff
        if name == "main":
            solution = Solution()
            nums1 = [1, 2, 4]
            print(solution.maxAdjacentDistance(nums1))
            nums2 = [-5, -10, -5]
            print(solution.maxAdjacentDistance(nums2))