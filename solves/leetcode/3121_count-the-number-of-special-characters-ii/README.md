# [3121_count-the-number-of-special-characters-ii](https://leetcode.com/problems/count-the-number-of-special-characters-ii/)

## Info

### Difficulty

MEDIUM

### Tags

- Hash Table
- String

## **COMMENTS**

> track the states for eacyh character

```
/**
* 0 start
* 1 lowercase found
* 2 uppercase found
*
* if 0
*  * upon finding lowercase, set to 1
* if 1
*  * upon finding uppercase, set to 2
* if 2
*  * upon finding lowercase, set to 3
*/
```
