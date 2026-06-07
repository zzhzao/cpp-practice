class Solution {
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    bool vis[301][301];
    int m, n;
public:
    void solve(vector<vector<char>>& board) {

        m = board.size();
        n = board[0].size();
        vector<vector<char>> ret(m, vector<char>(n, 'X'));
        for (int i = 0;i < m;i++)
        {
            for (int j = 0;j < n;j++)
            {
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && (board[i][j] == 'O'))
                {
                    bfs(board, ret, i, j);
                }
            }
        }
        board = ret;
    }
    void bfs(vector<vector<char>>& board, vector<vector<char>>& ret, int i, int j)
    {
        queue<pair<int, int>> q;
        q.push({ i,j });
        ret[i][j] = 'O';
        vis[i][j] = true;
        while (q.size())
        {
            auto [a, b] = q.front();
            q.pop();
            for (int k = 0; k < 4;k++)
            {
                int x = a + dx[k];
                int y = b + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O' && !vis[x][y])
                {
                    q.push({ x,y });
                    ret[x][y] = 'O';
                    vis[x][y] = true;
                }
            }
        }
    }
};