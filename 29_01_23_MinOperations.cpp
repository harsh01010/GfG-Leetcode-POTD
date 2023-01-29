/*
Min operations

Input:
a = 5, b = 12
Output:
2
Explanantion:
In first operation replace
a = a&4 = 4
after that replace
b = b&6 = 4
Hence both are same after applying two
operations.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

*/
// c++ solution:

class Solution
{
public:
    int solve(int a, int b)
    {
        // code here
        if (a == b)
            return 0;
        return (((a & b) == a) or ((a & b) == b)) ? 1 : 2;
    }
};