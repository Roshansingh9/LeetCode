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
    private:
    int cal_height(TreeNode* root){
        if(!root) return 0;
        int lh=cal_height(root->left);
        int rh=cal_height(root->right);
        return 1+max(lh,rh);

    }
public:
    bool isBalanced(TreeNode* root) {
       if(!root) return true;
        int left=cal_height(root->left);
        int right=cal_height(root->right);
        if(abs(left - right) > 1) return false;
        bool lh=isBalanced(root->left);
        bool rh=isBalanced(root->right);
        if(!rh || !lh) return false;
        return true;
    }
};