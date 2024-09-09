/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int a = 0, b = m-1, c = 0, d = n-1;
        while(a<=b && c<=d && head!=NULL){
            for(int i=c;i<=d;i++){
                if(head!=NULL){
                    ans[a][i] = head->val;
                    head = head->next;
                }
                else {break;}
            }
            if(a>b || c>d || head==NULL){
                break;
            }
            a++;
            for(int i=a;i<=b;i++){
                if(head!=NULL){
                    ans[i][d] = head->val;
                    head = head->next;
                } else {break;}
            }
            if(a>b || c>d || head==NULL){
                break;
            }
            d--;
            for(int i=d;i>=c;i--){
                if(head!=NULL){
                    ans[b][i] = head->val;
                    head = head->next;
                } else {break;}               
            }
            if(a>b || c>d || head==NULL){
                break;
            }
            b--;
            for(int i=b;i>=a;i--){
                if(head!=NULL){
                    ans[i][c] = head->val;
                    head = head->next;  
                }
                else {break;}
            }
            if(a>b || c>d || head==NULL){
                break;
            }
            c++;
        }
        return ans;
    }
};