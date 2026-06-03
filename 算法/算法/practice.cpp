class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        if (root == nullptr)
        {
            return ret;
        }
        q.push(root);
        int level = 0;
        while (q.size())
        {

            int sz = q.size();
            vector<int> tmp;
            for (int i = 0; i < sz;i++)
            {
                TreeNode* node = q.front();
                tmp.push_back(node->val);
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
                q.pop();
            }
            if (level % 2 == 1)
            {
                reverse(tmp.begin(), tmp.end());
            }
            level++;
            ret.push_back(tmp);
        }
        return ret;
    }
};