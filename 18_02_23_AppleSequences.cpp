/*
 There is a string of size n containing only 'A' and 'O'. 'A' stands for Apple, and 'O' stands for Orange. We have m number of spells, each spell allows us to convert an orange into an apple.

Find the longest sequence of apples you can make, given a string and the value of m.

Input:
N = 5
M = 1
arr[] = 'AAOAO'
Output: 4 
Explanation: Changing the orange at 
3rd position into an apple gives 
us the maximum possible answer.


*/
//c++ solution:
class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code here 
        int ans = 0;
        int st = 0;
        for(int i=0;i<n;i++)
        {
            if(m>0 && arr[i]=='O')
            {
                m--;
            }
            else
            {
                if(arr[i]=='O')
                {
                while(arr[st]!='O')
                {
                    st++;
                }
                st++;
                }
                
            }
            ans = max(ans,i-st+1);
        }
        return ans;
    }
};