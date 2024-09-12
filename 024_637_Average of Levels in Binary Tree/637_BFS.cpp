/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root)
    {
        vector<double> ans;
        queue<TreeNode*> q;
        long sum = 0;
        int count = 0;

        q.push(root);
        q.push(NULL);    // To mark the end of a level
        while (q.empty() == false) {
            TreeNode* cur = q.front();    // (1)
            q.pop();
            if (!cur) {
                ans.push_back((double)sum / count);    // Calculating averages
                sum = 0;
                count = 0;
                // (2) All level n+1 nodes are enqueued when all level n nodes
                // are poped. Thus a NULL is pushed to mark the end of
                // level n+1 here.
                q.push(NULL);
                if (!q.front())
                    break;
            } else {
                count++;
                sum += cur->val;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }

        return ans;
    }
};