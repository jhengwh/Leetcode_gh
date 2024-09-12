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
    //  Stores ( sum of a level , No. of elements in that level )
    vector<pair<long, int>> count;

    void dfs(TreeNode* root, int depth)
    {
        if (!root)
            return;
        // (1) To check if we have entry corresponding to current depth;
        // if we are at depth 1 and only depth 0 is completed, then
        // count.size() = 1 <= depth = 1, needs for an new entry.
        if (count.size() <= depth) {
            count.push_back({ root->val, 1 });
        } else {
            count[depth].first += root->val;
            count[depth].second++;
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    vector<double> averageOfLevels(TreeNode* root)
    {
        count.clear();
        dfs(root, 0);
        vector<double> ans;
        for (int i = 0; i < count.size(); i++) {
            ans.push_back((double)count[i].first / count[i].second);    // Calculating averages
        }
        return ans;
    }
};