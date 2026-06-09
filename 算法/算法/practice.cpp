class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> hash;
        for (auto e : wordList)
        {
            hash[e]++;
        }
        unordered_map<string, int> vis;

        int step = 1;
        queue<string> q;
        q.push(beginWord);
        vis[beginWord]++;
        while (q.size())
        {
            step++;
            int sz = q.size();
            for (int i = 0;i < sz;i++)
            {
                string str = q.front();
                q.pop();
                for (int j = 0;j < str.size();j++)
                {
                    string tmp = str;
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        tmp[j] = ch;
                        if (hash[tmp] && !vis[tmp])
                        {
                            q.push(tmp);
                            vis[tmp]++;
                        }
                        if (hash[tmp] && tmp == endWord)
                        {
                            return step;
                        }
                    }
                }
            }
        }
        return 0;
    }
};