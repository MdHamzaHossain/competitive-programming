# [1183-A-Nearest Interesting Number](https://codeforces.com/problemset/problem/1183/A)

## Info

### Rating

800

### Tags

- implementation

## __COMMENTS__

> Generate the vector and lower bound it

```js
copy((function(){
    let res = [];
    for(let i =0; i< 1008; i++){
        if((`${i}`.split("").reduce((acc,curr) => (+acc) + (+curr),0)) % 4 == 0 ) res.push(i);
    } 
    return res;
}
    )().join("," ))
```
