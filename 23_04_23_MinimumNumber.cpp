/*
You are given an array arr of n elements. In one operation you can pick two indices i and j, such that arr[i] >= arr[j] and replace the value of arr[i] with (arr[i] - arr[j]). You have to minimize the values of the array after performing any number of such operations.

returns the maximum number which is minimized after performing operations.
*/
// c++ solution , using gcd:

class Solution
{
public:
    int hcf(int a, int b)
    {
        if (b == 0)
            return a;
        return hcf(b, a % b);
    }
    int minimumNumber(int n, vector<int> &arr)
    {

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res = hcf(res, arr[i]);
        }

        return res;
    }
}