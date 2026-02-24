/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

public:
    int sum = 0;
    void dfs(TreeNode* node, int curr) {
        if (!node)
            return;
        curr = (curr << 1) | node->val;
        if (!node->left && !node->right) {
            sum += curr;
            return;
        }
        dfs(node->left, curr);
        dfs(node->right, curr);
    }

    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
};