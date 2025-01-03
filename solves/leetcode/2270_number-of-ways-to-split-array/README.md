# [2270_number-of-ways-to-split-array](https://leetcode.com/problems/number-of-ways-to-split-array/submissions/1496182859/?envType=daily-question&envId=2025-01-03)

## Info

### Difficulty

Medium

### Tags

- Array
- Prefix Sum

## __COMMENTS__

> if i get the total, going from the back, i need to check if,
`total - sumFromTheBack >= sumFromTheBack`, then increment
swap that around,
`total >= 2* sumFromTheBack`
