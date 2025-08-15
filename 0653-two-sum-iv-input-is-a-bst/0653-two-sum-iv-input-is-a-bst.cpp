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
    void inorder(TreeNode* root,vector<int>&  in_order){
         if(!root) return;
         inorder(root->left,in_order);
         in_order.push_back(root->val);
         inorder(root->right,in_order);

    }

    bool twosum(vector<int>& nums,int& k){
        int start=0;
        int end=nums.size()-1;
        while(start<end){
            int sum=nums[start]+nums[end];
            if(sum==k) return true;
            else if(sum>k){
                end--;
            }else{
                start++;
            }
        }
        return false;
    }
public:
    bool findTarget(TreeNode* root, int k) {
       vector<int> ans;
       inorder(root,ans);
       return twosum(ans,k); 
    }
};