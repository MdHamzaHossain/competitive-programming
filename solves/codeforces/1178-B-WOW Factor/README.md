# [1178-B-WOW Factor](https://codeforces.com/problemset/problem/1178/B)

## Info

### Rating

1300

### Tags

- dp
- strings

## __COMMENTS__

> This can be solved linearly. For every Os, track the amount of possible Ws before and after it. multiply that.

### Steps

- Count Ws and push to `wSBeforeOs` for every O
- Reverse the string
- Count Ws and push to `wSAfterOs` for every O
- Reverse `wSAfterOs`
- Loop and multiply both and add to `sum`
