# [3360_stone-removal-game](https://leetcode.com/problems/stone-removal-game/)

## Info

### Difficulty

EASY

### Tags

- Math
- Simulation

## __COMMENTS__

> if n < 10, alice loses, take turns (rotating boolean), start with neg=9. decrement on each turn. n-=neg,  if the current turn holder can't remove all neg (negative n) they lose, if it's 0 at the end, the other one loses. 
