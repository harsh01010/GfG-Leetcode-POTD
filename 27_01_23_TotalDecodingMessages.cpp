/*

Example 1:

Input: str = "123"
Output: 3
Explanation: "123" can be decoded as "ABC"(123),
"LC"(12 3) and "AW"(1 23).

Example 2:

Input: str = "90"
Output: 0
Explanation: "90" cannot be decoded as it's an invalid string and we cannot decode '0'.

Expected Time Complexity: O(n)
Expected Space Complexity: O(n) where n  = |str|


*/

// c++ iterative sloution using DP:

class Solution
{
public:
    int CountWays(string str)
    {
        // Code here
        int n = str.length();
        int dp[n];
        dp[0] = str[0] != '0' ? 1 : 0;
        for (int i = 1; i < n; i++)
        {
            if (str[i] == '0' and str[i - 1] == '0')
            {
                dp[i] = 0;
            }
            else if (str[i] != '0' and str[i - 1] == '0')
            {
                dp[i] = dp[i - 1] % 1000000007;
            }
            else if (str[i] == '0' and str[i - 1] != '0')
            {
                if (str[i - 1] == '1' || str[i - 1] == '2')        // 10 or  20 will be valid
                    dp[i] = (i >= 2 ? dp[i - 2] : 1) % 1000000007; // 10 -> if there are more previous charactors then dp[i-2] else only 1 -> 10
                else
                    dp[i] = 0;
            }
            else // at both i-1 and i there are non zeros
            {
                int x = stoi(str.substr(i - 1, 2));
                if (x <= 26)
                {
                    dp[i] = (dp[i - 1] % 1000000007) + (i >= 2 ? dp[i - 2] : 1) % 1000000007;
                }
                else
                {
                    dp[i] = dp[i - 1] % 1000000007;
                }
            }
        }

        return dp[n - 1] % 1000000007;
    }
};