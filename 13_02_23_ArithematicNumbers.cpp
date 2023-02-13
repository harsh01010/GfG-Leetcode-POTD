/*
Input: A = 1, B = 3, C = 2
Output: 1
Explaination: 3 is the second term of the
sequence starting with 1 and having a common
difference 2.
*/
// c++ solution:
//  User function Template for C++

class Solution
{
public:
    int inSequence(int A, int B, int C)
    {
        // code here
        if (C == 0)
            return A == B;
        return (B - A) % C == 0 && (B - A) / C >= 0;
    }
};