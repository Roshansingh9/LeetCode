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
    int max_diameter=INT_MIN;
    private:
    int cal_height(TreeNode* root){
        if(!root) return 0;
        int lh=cal_height(root->left);
        int rh=cal_height(root->right);
        
        max_diameter=max(max_diameter,lh+rh);
        return 1+max(lh,rh);

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        cal_height(root);
        return max_diameter;
    }
};