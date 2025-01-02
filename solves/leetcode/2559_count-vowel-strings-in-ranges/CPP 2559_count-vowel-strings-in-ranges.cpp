class Solution
{
public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        map<char, int> vows = {
            {'a', 1},
            {'e', 1},
            {'i', 1},
            {'o', 1},
            {'u', 1}};
        vector<int> goods;
        for (int i = 0; i < words.size(); i++)
        {
            string w = words[i];
            if ((vows[w[0]] && vows[w[w.size() - 1]]))
                goods.push_back(i);
        }
        vector<int> res;
        for (auto e : queries)
        {

            // LINEAR LOOP
            // int count= e[1] - e[0] + 1;
            // for(int j=0; j < bads.size(); j++){
            //     if( bads[j] >=e[0] && bads[j] <=e[1]) count--;
            // }

            // 2log(n)
            vector<int>::iterator ui = upper_bound(goods.begin(), goods.end(), e[1]);
            vector<int>::iterator li = lower_bound(goods.begin(), goods.end(), e[0]);
            res.push_back(ui - li);
        }
        return res;
    }
};
/**
function vowelStrings(words: string[], queries: number[][]): number[] {
    let vows = {
        a: 1,
        e: 1,
        i: 1,
        o: 1,
        u: 1,
    };
    let bads = [];
    words.forEach((w, i) => {
        if (!(vows[w[0]] && vows[w[w.length - 1]])) bads.push(i);
    });
    return queries.map((e) => {
        let count = e[1] - e[0] + 1 - bads.filter((a) => a >= e[0] && a <= e[1]).length;
        //for (let i=e[0]; i <=Math.min(e[1], words.length-1); i++ ){
        //    if(startsAndEnds[i]) count++;
        //}
        return count;
    });
}
**/
/**
SECOND IMPL, (STILL SLOW??)
function vowelStrings(words: string[], queries: number[][]): number[] {
    let vows = {
            'a':1, 'e': 1, 'i':1, 'o':1, 'u':1
        };
    let startsAndEnds = words.map((w) => {
        if(vows[w[0]] && vows[w[w.length-1]];
    })
    return queries.map(e => {
        let count =0;

        for (let i=e[0]; i <=Math.min(e[1], words.length-1); i++ ){
            if(startsAndEnds[i]) count++;
        }
        return count;
    })
};
 */
/**
FIRST IMPL ( i know this won't work)
function vowelStrings(words: string[], queries: number[][]): number[] {
    let vows = {
            'a':1, 'e': 1, 'i':1, 'o':1, 'u':1
        };
    return queries.map(e => {
        let count =0;

        for (let i=e[0]; i <=Math.min(e[1], words.length-1); i++ ){
            const word = words[i];
            if(vows[word[0]] && vows[word[word.length-1]]) count++;
        }
        return count;
    })
};
 */
