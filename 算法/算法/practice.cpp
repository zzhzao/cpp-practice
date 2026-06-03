
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        queue<Node*> q;
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
                Node* node = q.front();
                tmp.push_back(node->val);
                for (Node* e : node->children)
                {
                    if (e != nullptr)
                        q.push(e);
                }
                q.pop();
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};