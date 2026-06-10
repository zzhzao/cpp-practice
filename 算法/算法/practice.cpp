class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        vector<pair<int, int>> trees;
        int m = forest.size();
        int n = forest[0].size();
        for (int i = 0;i < m;i++)
        {
            for (int j = 0;j < n;j++)
            {
                if (forest[i][j] > 1)
                {
                    trees.push_back({ i,j });
                }
            }
        }
        sort(trees.begin(), trees.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
            return forest[a.first][a.second] < forest[b.first][b.second];
            });
        int ret = 0;
        int x = 0;
        int y = 0;
        for (auto [a, b] : trees)
        {
            int step = bfs(forest, x, y, a, b);
            if (step == -1)  return -1;
            ret += step;
            x = a;
            y = b;
        }
        return ret;
    }
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    int bfs(vector<vector<int>>& forest, int bx, int by, int ex, int ey)
    {
        if (ex == bx && ey == by) return 0;
        queue<pair<int, int>> q;
        int m = forest.size();
        int n = forest[0].size();
        bool vis[51][51];
        memset(vis, 0, sizeof(vis));
        q.push({ bx,by });
        vis[bx][by] = true;
        int step = 0;
        while (q.size())
        {
            step++;
            int sz = q.size();
            while (sz--)
            {
                auto [a, b] = q.front();
                q.pop();
                for (int i = 0; i < 4;i++)
                {
                    int x = a + dx[i];
                    int y = b + dy[i];
                    if (x >= 0 && x < m && y >= 0 && y < n && forest[x][y] != 0 && !vis[x][y])
                    {

                        if (x == ex && y == ey)
                        {
                            return step;
                        }
                        q.push({ x,y });
                        vis[x][y] = true;
                    }
                }
            }
        }
        return -1;
    }
};