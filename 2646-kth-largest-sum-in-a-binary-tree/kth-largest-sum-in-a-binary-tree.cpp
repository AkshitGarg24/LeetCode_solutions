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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long int> s;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            long long int sum = 0;
            int x = q.size();
            for (int i = 0; i < x; i++) {
                TreeNode* x = q.front();
                q.pop();
                sum += x->val;
                if (x->left != NULL) {
                    q.push(x->left);
                }
                if (x->right != NULL) {
                    q.push(x->right);
                }
            }
            s.push(sum);
        }
        if (k > s.size()) {
            return -1;
        }
        k--;
        while(k--){
            s.pop();
        }
        return s.top();
    }
};