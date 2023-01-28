/*

Input: S1="coder", S2="ocder"
Output: Yes
Explanation: ocder is a scrambled
form of coder.

    ocder
   /    \
  oc    der
 / \
o   c

As "ocder" can represent it
as a binary tree by partitioning
it into two non-empty substrings.
We just have to swap 'o' and 'c'
to get "coder".


Input: S1="abcde", S2="caebd"
Output: No
Explanation: caebd is not a
scrambled form of abcde.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N2)
*/

// c++ solution:

// recursive code  , gives TLE
class Solution
{
public:
    bool isScramble(string a, string b)
    {
        // code here
        if (a == b)
            return true;
        if (a.length() != b.length())
            return false;
        if (a.length() <= 1)
            return false;
        int n = a.length();
        for (int i = 1; i <= n - 1; i++)
        {

            string s1 = a.substr(0, i), s2 = b.substr(n - i, i), s3 = a.substr(i, n - i), s4 = b.substr(0, n - i);
            if (isScramble(s1, s2) and isScramble(s3, s4) == true)
                return true;
            s2 = b.substr(0, i), s4 = b.substr(i, n - i);
            if (isScramble(s1, s2) and isScramble(s3, s4) == true)
                return true;
        }
        return false;
    }
};

// recursive code optimized with memoization , and accepted

class Solution
{
public:
    unordered_map<string, int> ump;
    int getUmp(string a, string b)
    {
        a.push_back(' ');
        a.append(b);

        if (ump.find(a) != ump.end())
            return ump[a];
        else
            return -1;
    }
    void setUmp(string a, string b, bool x)
    {
        a.push_back(' ');
        a.append(b);
        if (x)
            ump[a] = 1;
        else
            ump[a] = 0;
    }
    bool isScramble(string a, string b)
    {
        // code here
        if (a == b)
            return true;
        if (a.length() != b.length())
            return false;
        if (a.length() <= 1)
            return false;

        // 1. 0 , i ,, n-i,i 2. i , n-i , 0 , n-i
        // 1. 0,i ,, 0,i 2. i , n-i ,, i,n-i
        int n = a.length();
        for (int i = 1; i <= n - 1; i++)
        {

            string s1 = a.substr(0, i), s2 = b.substr(n - i, i), s3 = a.substr(i, n - i), s4 = b.substr(0, n - i);
            // if(isScramble(s1 , s2) and isScramble(s3,s4) == true) return true;
            // s2 = b.substr(0,i) , s4 = b.substr(i,n-i);
            // if(isScramble(s1,s2) and isScramble(s3,s4) == true) return true;
            int x = getUmp(s1, s2);
            if (x == -1)
                setUmp(s1, s2, isScramble(s1, s2));
            x = getUmp(s1, s2);

            int y = getUmp(s3, s4);
            if (y == -1)
                setUmp(s3, s4, isScramble(s3, s4));
            y = getUmp(s3, s4);

            if (x == 1 and y == 1)
                return true;

            s2 = b.substr(0, i), s4 = b.substr(i, n - i);

            x = getUmp(s1, s2);
            if (x == -1)
                setUmp(s1, s2, isScramble(s1, s2));
            x = getUmp(s1, s2);

            y = getUmp(s3, s4);
            if (y == -1)
                setUmp(s3, s4, isScramble(s3, s4));
            y = getUmp(s3, s4);

            if (x == 1 and y == 1)
                return true;
        }
        return false;
    }
};