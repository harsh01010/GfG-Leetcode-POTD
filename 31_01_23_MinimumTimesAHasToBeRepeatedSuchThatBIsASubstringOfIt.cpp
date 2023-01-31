/*
Input:
A = "abcd"
B = "cdabcdab"
Output:
3
Explanation:
Repeating A three times (abcdabcdabcd),
B is a substring of it. B is not a substring
of A when it is repeated less than 3 times.

Input:
A = "ab"
B = "cab"
Output :
-1
Explanation:
No matter how many times we repeat A, we can't
get a string such that B is a substring of it.

*/
// c++ solution:

class Solution {
  public:
  int firstMatch(string a , string b)
{
for(int i=0;i<a.length();i++)
 if(a[i] == b[0]) return i;
return -1;
}
int minRepeats(string A, string B) {
        // code here
    int ind = firstMatch(A,B);
    if(ind==-1) return -1;
    int res = 1;
    for(int i=0;i<B.length();i++)
    {
    if(ind==A.length())
    res++, ind%=A.length();

    if(A[ind] != B[i]) return -1;
    ind++;
        
}
return res;
}
};