/*

Given N nodes of a tree and a list of edges. Find the minimum number of nodes to be selected to light up all the edges of the tree.
An edge lights up when at least one node at the end of the edge is selected.


Input:
N = 6
edges[] = {(1,2), (1,3), (2,4), (3,5), (3,6)}
Output: 2
Explanation: Selecting nodes 2 and 3 lights
up all the edges.


Input:
N = 3
arr[] = {(1,2), (1,3)}
Output: 1
Explanation: Selecting Node 1 
lights up all the edges.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/

// attempt this question before : https://leetcode.com/problems/binary-tree-cameras/
//only difference in both question is , on leetcode they have provided root of tree , but here we have to construct a tree.

// c++ code:

class Solution{
  public:
    int countVertex(int N, vector<vector<int>>edges){
        // code here
        vector<int> graph[N+1];
        for(vector<int> e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<vector<int>> dp(N+1,vector<int>(2,-1));
        vector<vector<int>> dp1(N+1,vector<int>(2,-1));
        return min(f(graph,1,0,-1,dp),f(graph,1,1,-1,dp1)+1);
    }
    
    int f(vector<int> graph[],int src,int isLighted,int prnt,vector<vector<int>>& dp) {
        if(dp[src][isLighted]!=-1) return dp[src][isLighted];
        int ans=0;
        for(int nbr : graph[src]) {
            if(nbr!=prnt) {
                if(isLighted==0) {
                    int f1 = f(graph,nbr,1,src,dp);
                    ans+=f1+1;
                } else {
                    int f0 = f(graph,nbr,0,src,dp);
                    int f1 = f(graph,nbr,1,src,dp);
                    ans+=min(f0,f1+1);
                }
            }
        }
        return dp[src][isLighted]=ans;
    }
};