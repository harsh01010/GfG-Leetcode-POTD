/*
Given an integer N, You need to find the Nth smallest number which only contains odd digits i.e. 1,3,5,7,9 means no even digits are allowed on that number (12 will not consider). For example, the starting numbers which only contain odd digits are 1,3,5,7,9,11,13,15,17,19,31,33,35 and so on.

approach:
using base 5 number system:
    digits -> 0,1,2,3,4,5
    2*digits + 1 -> 1,3,5,7,9 -> 9,1,3,5,7
*/
// c++ solution:
long long findNumber(long long N)
{
    int Dig[] = {9, 1, 3, 5, 7};
    long long res = 0, mul = 1;
    while (N)
    {
        res += Dig[N % 5] * mul;
        mul *= 10;
        N = N % 5 ? N / 5 : N / 5 - 1;
    }
    return res;
}