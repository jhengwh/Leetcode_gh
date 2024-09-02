/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void traverseInorder(struct TreeNode* node, int* pMinDiff, int* pPrev)
{
    if (node == NULL)
        return;

    traverseInorder(node->left, pMinDiff, pPrev);

    if (*pPrev >= 0) {
        int diff = node->val - *pPrev;
        *pMinDiff = (diff < *pMinDiff) ? diff : *pMinDiff;
    }
    *pPrev = node->val;

    traverseInorder(node->right, pMinDiff, pPrev);
}

int getMinimumDifference(struct TreeNode* root)
{
    int minDiff = INT_MAX;
    int prev = -1;

    traverseInorder(root, &minDiff, &prev);

    return minDiff;
}