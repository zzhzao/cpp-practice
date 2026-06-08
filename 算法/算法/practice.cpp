class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string, int> hash;
        int step = 0;
        for (auto e : bank)
        {
            hash[e]++;
        }
        string change = "ACGT";
        queue<string> q;
        q.push(startGene);
        unordered_map<string, int> vis;
        while (q.size())
        {
            step++;
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                string str = q.front();
                q.pop();
                for (int j = 0;j < 8;j++)
                {
                    string tmp = str;
                    for (int k = 0; k < 4;k++)
                    {
                        tmp[j] = change[k];
                        if (hash[tmp] && !vis[tmp])
                        {
                            q.push(tmp);
                            vis[tmp]++;
                        }
                        if (hash[tmp] && tmp == endGene)
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