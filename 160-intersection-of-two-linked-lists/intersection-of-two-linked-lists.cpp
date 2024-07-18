/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        ListNode *b = headB;
        int l1 = 0;
        int l2 = 0;
        while(a!=NULL && b!=NULL){
            l1++;
            l2++;
            a = a->next;
            b = b->next;
        }
        while(a!=NULL){
            l1++;
            a = a->next;
        }
        while(b!=NULL){
            l2++;
            b = b->next;
        }
        if(l1-l2>=0){
            a = headA;
            b = headB;
        } else {
            a = headB;
            b = headA;
        }
        int x = abs(l1-l2);
        while(x--){
            a = a->next;
        }
        while(a!=NULL){
            if(a==b){
                return a;
            }
            a = a->next;
            b = b->next;
        }
        return NULL;
    }
};