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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode *> q;
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int x = q.size();
            vector<int> m;
            while(x--){
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                
                m.push_back(q.front()->val);
                q.pop();
            }
            ans.push_back(m);
        }
        return ans;
    }
};