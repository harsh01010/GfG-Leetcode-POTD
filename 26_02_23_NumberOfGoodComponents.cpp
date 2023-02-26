/*
Given an undirected graph with V vertices(numbered from 1 to V) and E edges. Find the number of good components in the graph.
A component of the graph is good if and only if the component is a fully connected component.
Note: A fully connected component is a subgraph of a given graph such that there's an edge between every pair of vertices in a component, the given graph can be a disconnected graph. Consider the adjacency list from index 1.
*/

// c++ solution:
class Solution
{
public:
    vector<int> vis;
    void dfs(vector<vector<int>> &adj, int i, int &vercnt, int &edgcnt)
    {
        vis[i] = 1;
        vercnt++;
        for (auto it : adj[i])
        {
            edgcnt++;
            if (!vis[it])
            {
                dfs(adj, it, vercnt, edgcnt);
            }
        }
    }
    int findNumberOfGoodComponent(int V, vector<vector<int>> &adj)
    {
        vis = vector<int>(V + 1, 0);
        int res = 0;
        for (int i = 1; i <= V; i++)
        {
            if (vis[i] == 0)
            {
                int vcnt = 0, ecnt = 0;
                dfs(adj, i, vcnt, ecnt);
                ecnt /= 2;
                if (ecnt == (vcnt * (vcnt - 1)) / 2)
                    res++;
            }
        }
        return res;
    }
};