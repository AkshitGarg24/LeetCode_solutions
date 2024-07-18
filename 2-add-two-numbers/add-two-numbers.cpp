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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *a = l1;
        ListNode *b = l2;
        ListNode *temp1;
        int x;
        int y = 0;
        while(a!=NULL && b!=NULL){
            x = (a->val+b->val+y);
            a->val = (x%10);
            y = x/10;
            temp1 = a;
            a = a->next;
            b = b->next;
        }
        while(a!=NULL){
            x = (a->val+y);
            a->val = x%10;
            y = x/10;
            temp1 = a;
            a = a->next;
        }
        while(b!=NULL){
            x = b->val+y;
            temp1->next = new ListNode(x%10);
            y = x/10;
            temp1 = temp1->next;
            b = b->next;
        }
        if(y!=0 && a==NULL){
            temp1->next = new ListNode(y);
        }
        
        
        return l1;
    }
};