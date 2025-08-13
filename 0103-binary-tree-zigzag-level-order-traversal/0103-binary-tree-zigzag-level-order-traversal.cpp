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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        int right = 0;
        while (!q.empty()) {
            int s = q.size();
            vector<int> level;
            for (int i = 0; i < s; i++) {
                TreeNode* temp = q.front();
                q.pop();

                if (temp->left != nullptr)
                    q.push(temp->left);
                if (temp->right != nullptr)
                    q.push(temp->right);

                level.push_back(temp->val);
            }
            if (right) {
                reverse(level.begin(), level.end());
                right = 0;
            } else {

                right = 1;
            }
            ans.push_back(level);
        }
        return ans;
    }
};