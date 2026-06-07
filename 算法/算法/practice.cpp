class Solution {
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    bool vis[301][301];
    int m, n;
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ret = 0;
        for (int i = 0;i < m;i++)
        {
            for (int j = 0;j < n;j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    bfs(grid, i, j);
                    ret++;
                }
            }
        }
        return ret;
    }
    void bfs(vector<vector<char>>& grid, int i, int j)
    {
        queue<pair<int, int>> q;
        q.push({ i,j });
        vis[i][j] = true;
        while (q.size())
        {
            auto [a, b] = q.front();
            grid[a][b] = '0';
            q.pop();
            for (int k = 0; k < 4;k++)
            {
                int x = a + dx[k];
                int y = b + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && !vis[x][y])
                {
                    vis[x][y] = true;
                    q.push({ x,y });
                }
            }
        }
    }
};