# [1144-A-Diverse Strings](https://codeforces.com/problemset/problem/1144/A)

## Info

### Rating

800

### Tags

- implementation
- strings

## __COMMENTS__

> have a bitset to track each char's presence, if a set bit is trying to be set, set `flag = false`, loop all 26 chars. have a `mode` flag, where `0 = range not started yet`, `1 = started range`,`2 range ended`,`range ended and something extraneous was found`, self explanatory
