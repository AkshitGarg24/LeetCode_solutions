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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> x;
        int size = 0;
        ListNode *temp = head;
        while(temp!=NULL){
            size++;
            temp = temp->next;
        }
        temp = head;
        int a = size/k;
        int b = size%k;
        for(int i=0;i<k;i++){
            ListNode *m = new ListNode(-1);
            ListNode *n = m;
            int q = a;
            cout<<q;
            while(q--){
                n->next = new ListNode(temp->val);
                temp = temp->next;
                n = n->next;
            }
            if(b>0){
                n->next = new ListNode(temp->val);
                temp = temp->next;
                b--;
            }
            x.push_back(m->next);
        }
        return x;
    }
};