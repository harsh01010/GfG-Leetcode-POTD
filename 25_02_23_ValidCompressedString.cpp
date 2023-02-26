/*
A special compression mechanism can arbitrarily delete 0 or more characters and replace them with the deleted character count.
Given two strings, S and T where S is a normal string and T is a compressed string, determine if the compressed string  T is valid for the plaintext string S.

Input:
S = "GEEKSFORGEEKS"
T = "G7G3S"
Output:
1
Explanation:
We can clearly see that T is a valid
compressed string for S.
*/

// c++ solution:

class Solution
{
public:
    int checkCompressed(string S, string T)
    {
        // code here
        int i = 0, j = 0;
        while (i < S.length() && j < T.length())
        {
            if (S[i] == T[j])
            {
                i++;
                j++;
                continue;
            }
            if (T[j] - '0' == 0)
            {
                j++;
                continue;
            }

            int count = 0;
            while (j < T.length() && isdigit(T[j]))
            {
                count = count * 10 + (T[j] - '0');
                j++;
            }

            i += count;
            if (count == 0)
                return 0;
        }
        return i == S.length() && j == T.length();
    }
};