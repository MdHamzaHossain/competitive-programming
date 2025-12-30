# [840_magic-squares-in-grid](https://leetcode.com/problems/magic-squares-in-grid/)

## Info

### Difficulty

Medium

### Tags

- Array
- Hash Table
- Math
- Matrix

## __COMMENTS__

> only 8 permutations of 1-9 are magic squares, the code to generating them:

```cpp
int main()
{
    string v = "";
    FORN(i, 1, 10)
    {
        v.PB(i + '0');
    }
    // cout << v << endl;
    vector<string> res;

    while (next_permutation(b2e(v)))
    {
        // cout << "DEB " << v << endl;
        bool ok = true;
        if (v[4] != '5')
        {
            ok = false;
        }
        FORN(i, 0, 3)
        {
            if (!(v[i] + v[i + 3] + v[i + 6] - ('0' * 3) == 15))
            {
                ok = false;
            }
        }
        FORN(i, 0, 3)
        {
            ll j = i * 3;
            if (!(v[j] + v[j + 1] + v[j + 2] - ('0' * 3) == 15))
            {
                ok = false;
            }
        }
        if (v[0] + v[4] + v[8] - ('0' * 3) != 15)
            ok = false;
        if (v[2] + v[4] + v[6] - ('0' * 3) != 15)
            ok = false;
        if (ok)
        {
            res.push_back(v);
        }
    }
    for (auto e : res)
    {
        cout << e << " " << endl;
    }
}
```
