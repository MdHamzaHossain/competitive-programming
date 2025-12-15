# [294-A-Shaass and Oskols](https://codeforces.com/problemset/problem/294/A)

## Info

### Rating

800

### Tags

- implementation
- math

## __COMMENTS__

> work with vector, have two extra slots, the 0 and the n +1 slot, for each query, `v[x + 1] += v[x] - y, v[x - 1] += y - 1, v[x] = 0` and display only the ones used
