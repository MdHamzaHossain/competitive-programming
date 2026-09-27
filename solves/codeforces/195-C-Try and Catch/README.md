# [195-C-Try and Catch](https://codeforces.com/contest/195/problem/C)

## Info

### Rating

1800

### Tags

- expression parsing
- implementation

## __COMMENTS__

> parse line, put into stringstream to parse words separately, use modes to track which category of input this is, i.e: try, catch or throw, parse the error type and the message separately, store the error type from the throw. use a stack and track which block scope you're working on. 
