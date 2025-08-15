class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
        TreeNode* curr = root;

        while (curr) {
            if (!curr->left) {
                
                if (prev && prev->val > curr->val) {
                    if (!first) first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            } 
            else {
                TreeNode* pre = curr->left;
                while (pre->right && pre->right != curr) {
                    pre = pre->right;
                }

                if (!pre->right) {
                    pre->right = curr;
                    curr = curr->left;
                } 
                else {
                    pre->right = nullptr;
                    if (prev && prev->val > curr->val) {
                        if (!first) first = prev;
                        second = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        if (first && second) {
            swap(first->val, second->val);
        }
    }
};
