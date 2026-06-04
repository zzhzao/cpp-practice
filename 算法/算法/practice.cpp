class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        queue<TreeNode*> q;
        if (root == nullptr)
        {
            return ret;
        }
        q.push(root);
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
            int num = tmp[0];
            for (auto e : tmp)
            {
                num = max(num, e);
            }
            ret.push_back(num);
        }
        return ret;
    }
};