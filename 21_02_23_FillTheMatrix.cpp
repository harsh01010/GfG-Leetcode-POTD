/*
Given a matrix with dimensions N x M, entirely filled with zeroes except for one position at co-ordinates X and Y containing '1'. Find the minimum number of iterations in which the whole matrix can be filled with ones.


*/
// c++ code:

bool under(int n, int m, int i, int j)
{
    return i > 0 && j > 0 && i <= n && j <= m;
}
int minIteration(int N, int M, int x, int y)
{
    // code here
    vector<vector<int>> vis(N + 1, vector<int>(M + 1, 0));
    vis[x][y] = 1;

    int di[] = {0, 0, -1, 1};
    int dj[] = {-1, 1, 0, 0};
    queue<pii> q;
    q.push({x, y});
    int step = 0;
    while (q.size())
    {
        int x = q.size();
        for (int l = 0; l < x; l++)
        {
            pii p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            for (int k = 0; k < 4; k++)
            {
                int ni = i + di[k];
                int nj = j + dj[k];
                if (under(N, M, ni, nj) && !vis[ni][nj])
                {
                    vis[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }
        step++;
    }

    return --step;
}

// this problem can also be solved in O(1) time  and space.