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
    int maxi=INT_MIN;
    int maxheight(TreeNode* root){
        if(root==nullptr) return 0;
        int lh=maxheight(root->left);
        int rh=maxheight(root->right);
        return max(lh,rh)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
       if(root==nullptr) return 0;
       int lh=maxheight(root->left);
        int rh=maxheight(root->right);
        maxi=max(maxi,lh+rh);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxi; 
    }
};