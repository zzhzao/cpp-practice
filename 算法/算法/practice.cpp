class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0, n = popped.size();
        for (auto e : pushed)
        {
            st.push(e);
            while (st.size() && st.top() == popped[i])
            {
                st.pop();
                i++;
            }
        }
        if (i == n)
        {
            return true;
        }
        return false;
    }
};