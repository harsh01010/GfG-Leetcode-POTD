/*
Append a character at the end of the string.
Append the string formed thus far to the end of the string. (This can not be done more than once.)

Input:
s = abcabca
Output: 5
Explanation: a -> ab -> abc -> abcabc 
-> abcabca


Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(1)
*/

// solution ::

class Solution {
  public:
    
    int matchStr(string s1 ,int i , string s2,int& maxLen)
    {
    int a = s1.length() , b = s2.length();
    if(!a || !b) return -1;
    if(s1[i] != s2[0]) return -1;
    if(b>a-i) return -1;
    if(s1.substr(i,b) == s2){
    maxLen =s2.length(); 
    return i + b;
    }
    else return -1;
    }
    int minOperation(string s) {
        // code here
       int x = s.length();
    string temp;
    int maxLen = 0;
    for(int i=0;i<x;i++)
    {
        if(  matchStr(s,i,temp,maxLen) != -1)
        {
            i = matchStr(s,i,temp,maxLen)-1;
            temp += temp;
        }
        else
        {
            temp.push_back(s[i]);
        }
    }
    if(maxLen>0)
    x = x-maxLen+1;
    return x;
    }
};



