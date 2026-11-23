# [1352_product-of-the-last-k-numbers](https://leetcode.com/problems/product-of-the-last-k-numbers/)

## Info

### Difficulty

Medium

### Tags

- Array
- Math
- Design
- Data Stream
- Prefix Sum

## **COMMENTS**

> .getProduct = function(k) { return this.nums.slice(this.nums.length - k, this.nums.length).reduce((acc, curr) => acc *
> curr, 1) };
