# [3412_find-mirror-score-of-a-string](https://leetcode.com/problems/find-mirror-score-of-a-string/description/)

## Info

### Difficulty

Medium

### Tags



## __COMMENTS__

> can be done in O(n) time, while inserting, keep a track of the same character's index in a deque, only push to it if the deque for the mirror is empty, otherwise, remove the last mirror's index off the deque, add the score
