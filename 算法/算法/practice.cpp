class Solution {
    typedef pair<int, int> PII;
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int prev = image[sr][sc];
        if (color == prev) return image;

        queue<PII> q;
        q.push({ sr,sc });

        while (q.size())
        {
            auto [a, b] = q.front();
            q.pop();
            image[a][b] = color;
            for (int i = 0;i < 4;i++)
            {
                int x = a + dx[i], y = b + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == prev)
                {
                    q.push({ x,y });
                }
            }
        }
        return image;
    }
};
