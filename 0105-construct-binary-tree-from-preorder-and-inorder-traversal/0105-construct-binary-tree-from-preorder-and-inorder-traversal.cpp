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
    TreeNode* helper(vector<int>& preorder, int pre_start, int pre_end,
                     vector<int>& inorder, int in_start, int in_end,
                     map<int, int>& mp) {
        if (pre_start > pre_end || in_start > in_end) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[pre_start]);
        int index = mp[root->val];
        int nodes = index - in_start;
        root->left = helper(preorder, pre_start + 1, pre_start + nodes, inorder,
                            in_start, index - 1, mp);
        root->right = helper(preorder, pre_start + nodes + 1, pre_end, inorder,
                             index + 1, in_end, mp);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) {
            return NULL;
        }
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return helper(preorder, 0, preorder.size() - 1, inorder, 0,
                      inorder.size() - 1, mp);
    }
};