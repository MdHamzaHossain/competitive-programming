# [349-A-Cinema Line](https://codeforces.com/problemset/problem/349/A)

## Info

### Rating

1100

### Tags

- greedy
- implementation

## __COMMENTS__

> cases, cases  

- track every `25` and `50`.
- For every 25, just increment
- For every 50, see if we have `any 25`, if so `decrement 25, increment 50`
- For every 100,
- - If there is `a minimum of one 25 and one 50`, `decrement the 50 and 25 count`
- - If there is `More than 3 25s`, `decrement the 25 count by 3`
- For every fallback case, set the `flag = false`
