class Solution {

    typedef pair<string, int> PSI;
    class cmp
    {
    public:
        bool operator()(const PSI& a, const PSI& b)
        {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<PSI, vector<PSI>, cmp> heap;

        unordered_map<string, int> hash;
        vector<string> ret;
        for (auto& e : words)
        {
            hash[e]++;
        }
        for (auto& e : hash)
        {
            heap.push(e);
            if (heap.size() > k)
            {
                heap.pop();
            }
        }

        while (k--)
        {
            ret.push_back(heap.top().first);
            heap.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};