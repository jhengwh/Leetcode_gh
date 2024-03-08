/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Divide-and-conquer
// Depth-first search (DFS)
// Recursive

/* Organized */
int maxDepth(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    int D_left = maxDepth(root->left);
    int D_right = maxDepth(root->right);
    D = (D_left > D_right) ? D_left + 1 : D_right + 1;
    return D;
}