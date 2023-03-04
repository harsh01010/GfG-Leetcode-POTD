/*
Input:
N=4
A={1,6,9,12}

Output:
0 5 8 14

Explanation:
For i=0, We do not need to perform any
operation, our array will be {1}->{1}.
And minimum number of operations
will be 0.

For i=1, We can choose to convert all
the elements from 0<=j<=i to 4, our
array will become {1,6}->{4,4}. And
minimum number of operations will be
|1-4|+|6-4|=5.

For i=2, We can choose to convert all
the elements from 0<=j<=i to 6, our
array will become {1,6,9}->{6,6,6} and
the minimum number of operations will
be |1-6|+|6-6|+|9-6|=8.

Similarly, for i=3, we can choose to
convert all the elements to 8,
{1,6,9,12}->{8,8,8,8}, and the
minimum number of operations will be 14.
*/
// c++ solution:
class Solution
{
public:
    vector<int> optimalArray(int n, vector<int> &a)
    {
        // Code here
        vector<int> res;
        res.push_back(0);
        for (int i = 1; i < n; i++)
        {
            res.push_back(res[i - 1] + (a[i] - a[i / 2]));
        }
        return res;
    }
};