class Solution {
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        bool vis[m][n];
        memset(vis, 0, sizeof(vis));
        queue<pair<int, int>> q;
        q.push({ entrance[0],entrance[1] });
        vis[entrance[0]][entrance[1]] = true;
        int step = 0;
        while (q.size())
        {
            step++;
            int sz = q.size();
            for (int j = 0; j < sz;j++)
            {
                auto [a, b] = q.front();
                q.pop();
                for (int i = 0;i < 4;i++)
                {
                    int x = a + dx[i];
                    int y = b + dy[i];
                    if (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.' && !vis[x][y])
                    {
                        q.push({ x,y });
                        vis[x][y] = true;
                        if (x == 0 || x == m - 1 || y == 0 || y == n - 1)
                        {
                            return step;
                        }
                    }
                }
            }
        }
        return -1;
    }
};