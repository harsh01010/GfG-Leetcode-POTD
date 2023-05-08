/*
You are given a binary string s and an integer m. You need to return an integer r. Where r = k%m, k is the binary equivalent of string s.
*/

// c++ solution :
class Solution
{
public:
    int modulo(string s, int m)
    {
        // code here
        int n = s.length();
        int k = 0, j = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            k = (k * 2 + ((int)(s.at(j++) - '0'))) % m;
        }
        return k % m;
    }
};