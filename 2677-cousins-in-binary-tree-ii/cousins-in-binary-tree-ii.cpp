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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root){
            return root;
        }
        root->val = 0;
        vector<TreeNode*> v;
        if (root->left) {
            root->left->val = 0;
            v.push_back(root->left);
        }
        if (root->right) {
            root->right->val = 0;
            v.push_back(root->right);
        }
        while (!v.empty()) {
            int sum = 0;
            vector<TreeNode*> nextLevel;

            for (TreeNode* node : v) {
                if (node->left) {
                    sum += node->left->val;
                    nextLevel.push_back(node->left);
                }
                if (node->right) {
                    sum += node->right->val;
                    nextLevel.push_back(node->right);
                }
            }

            for (TreeNode* node : v) {
                int q = 0;
                if (node->left)
                    q += node->left->val;
                if (node->right)
                    q += node->right->val;

                if (node->left) {
                    node->left->val = sum - q;
                }
                if (node->right) {
                    node->right->val = sum - q;
                }
            }
            v = nextLevel;
        }
        return root;
    }
};