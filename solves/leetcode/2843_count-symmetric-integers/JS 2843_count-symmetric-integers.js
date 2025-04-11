/**
 * @param {number} low
 * @param {number} high
 * @return {number}
 */
var countSymmetricIntegers = function(low, high)
{
    let res = 0;
    for (let i = low; i <= high; i++)
        if (i < 100 &&i % 11 == = 0)
            res++;
        else if (1000 <= i && i < 10000)
            if (Math.floor(i / 1000) + Math.floor((i % 1000) / 100) == = Math.floor((i % 100) / 10) + (i % 10))
                res++;

    return res;
};