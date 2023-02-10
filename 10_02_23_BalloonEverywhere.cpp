/*
Input:
S: loonbalxballpoon
Output: 2
Explanation:
Here, the number of occurence of 'b' = 2
of occurence of 'a' = 2
of occurence of 'l' = 4
of occurence of 'o' = 4
of occurence of 'n' = 2
So, we can form 2 "balloon" using the letters.
*/
// cpp solution:
int maxInstance(string s)
{
    string target = "ballon";
    unordered_map<char, int> ump;
    for (auto it : s)
        ump[it]++;
    int res = -1;
    if (ump.find('l') != ump.end())
        ump['l'] = ump['l'] / 2;
    else
        return 0;
    if (ump.find('o') != ump.end())
        ump['o'] = ump['o'] / 2;
    else
        return 0;
    for (auto it : target)
    {
        if (ump.find(it) == ump.end())
            return 0;
        else
        {
            if (res == -1)
                res = ump[it];
            else
                res = min(res, ump[it]);
        }
    }
    return res;
}