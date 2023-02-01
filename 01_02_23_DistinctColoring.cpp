
/*

There is a row of N houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color. Find the minimum cost to paint all houses.

The cost of painting each house in red, blue or green colour is given in the array r[], g[] and b[] respectively.


Input:
N = 3
r[] = {1, 1, 1}
g[] = {2, 2, 2}
b[] = {3, 3, 3}
Output: 4
Explanation: We can color the houses 
in RGR manner to incur minimum cost.
We could have obtained a cost of 3 if 
we coloured all houses red, but we 
cannot color adjacent houses with 
the same color.

Input:
N = 3
r[] = {2, 1, 3}
g[] = {3, 2, 1}
b[] = {1, 3, 2} 
Output: 3
Explanation: We can color the houses
in BRG manner to incur minimum cost.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


*/

//c++ solution:

class Solution{   
public:
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here 
        
        long long int arr[N][3];
        arr[0][0] = r[0];
        arr[0][1] = g[0];
        arr[0][2] = b[0];
        
        for(int i=1;i<N;i++)
        {
            for(int j = 0;j<3;j++)
            {
                 if(j==0)
                 arr[i][j] = r[i] + min(arr[i-1][j+1] , arr[i-1][j+2]);
                 if(j==1)
                 arr[i][j] = g[i]+ min(arr[i-1][j-1],arr[i-1][j+1]);
                 if(j==2)
                 arr[i][j] = b[i] + min(arr[i-1][j-1],arr[i-1][j-2]);
            }
        }
         return min(arr[N-1][0] , min(arr[N-1][1],arr[N-1][2]));
    }
};