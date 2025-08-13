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
    vector<int> rightSideView(TreeNode* root) {
      vector<int>ans;
      if(root==nullptr) return ans;
      queue<TreeNode*>q;
      q.push(root);
      while(!q.empty()){
        vector<int>level;
        int s=q.size();
        for(int i=0;i<s;i++){
        TreeNode* temp=q.front();
        q.pop();
        if(temp->right!=nullptr) q.push(temp->right);
        if(temp->left!=nullptr)  q.push(temp->left);
        level.push_back(temp->val);
        }
        ans.push_back(level[0]);
      }  
      return ans;
    }
};