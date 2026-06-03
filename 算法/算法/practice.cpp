class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<pair<TreeNode*, unsigned int>> q;
        q.push_back({ root, 1 });
        unsigned int ret = 0;

        while (q.size())
        {
            vector<pair<TreeNode*, unsigned int>> tmp;
            int sz = q.size();
            ret = max(ret, q[sz - 1].second - q[0].second + 1);


            for (auto& [x, y] : q)
            {
                if (x->left)
                    tmp.push_back({ x->left,2 * y });
                if (x->right)
                    tmp.push_back({ x->right,2 * y + 1 });
            }
            q = tmp;
        }
        return ret;
    }
};