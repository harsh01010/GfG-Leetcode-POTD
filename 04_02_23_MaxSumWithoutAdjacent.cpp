/*
Given an array Arr of size N containing positive integers. Find the maximum sum of a subsequence such that no two numbers in the sequence should be adjacent in the array.

Input:
N = 6
Arr[] = {5, 5, 10, 100, 10, 5}
Output: 110
Explanation: If you take indices 0, 3
and 5, then Arr[0]+Arr[3]+Arr[5] =
5+100+5 = 110.

*/

// c++ code:

class Solution
{
public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(int *arr, int n)
    {
        // code here
        int incS = arr[0], excS = 0;
        for (int i = 1; i < n; i++)
        {
            int temp = incS;
            incS = excS + arr[i];
            excS = max(temp, excS);
        }
        return max(incS, excS);
    }
};