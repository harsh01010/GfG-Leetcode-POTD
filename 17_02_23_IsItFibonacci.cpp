/*
Geek just learned about Fibonacci numbers.

The Fibonacci Sequence is the series of numbers: 0, 1, 1, 2, 3, 5, 8, 13, ...
where the next number is found by adding up the two numbers before it.

He defines a new series called Geeky numbers. Here the next number is the sum of the K preceding numbers.
You are given an array of size K, GeekNum[ ], where the ith element of the array represents the ith Geeky number. Return its Nth term.

Input:
N = 5, K = 3
GeekNum[] = {0, 1, 2}
Output:
6
Explanation:
Terms are 0, 1, 2, 3, 6.
So the 5th term is 6
*/

// c++ solution:
class Solution
{
public:
    long long solve(int N, int K, vector<long long> GeekNum)
    {
        // code here
        long long int ans = 0;
        for (int i = 0; i < K; i++)
            ans += GeekNum[i];

        GeekNum.push_back(ans);

        int j = K;
        for (int i = K + 1; i < N; i++)
        {
            long long int temp = GeekNum[i - 1] - GeekNum[i - K - 1] + GeekNum[i - 1];
            GeekNum.push_back(temp);
        }
        return GeekNum[N - 1];
    }
};