/*
Input:
n = 3
m = 3
c[][]: H H H
       H W H
       H H H
Output:
4 2 4
2 0 2
4 2 4
Explanation:
There is only one well hence all the houses present
in the corner of matrix will have to travel a minimum
distance of 4, 2 is for house to well and other two is
for well to house. And rest of the houses have to travel
a minimum distance of 2 (House -> Well -> House).
*/

// c++ solution using bfs:
bool isPoss(int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}
vector<vector<int>> chefAndWells(int n, int m, vector<vector<char>> &c)
{
    // Code here
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> res(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (c[i][j] == 'W')
            {
                vis[i][j] = 1;
                res[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (q.size())
    {
        int i = q.front().first, j = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int ni = i + dx[k], nj = j + dy[k];
            if (isPoss(ni, nj, n, m) && c[ni][nj] != 'N' && !vis[ni][nj])
            {
                vis[ni][nj] = 1;
                res[ni][nj] = res[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (c[i][j] == '.' || c[i][j] == 'N')
                res[i][j] = 0;
            else if (res[i][j] != -1)
                res[i][j] *= 2;
        }
    }

    return res;
}