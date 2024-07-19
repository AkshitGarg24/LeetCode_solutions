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
    ListNode *merge(ListNode *a,ListNode *b){
        ListNode *temp = new ListNode(-1);
        ListNode *x = temp;
        while(a!=NULL && b!=NULL){
            if(a->val<b->val){
                temp->next = a;
                a = a->next;
            } else {
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }
        while(a!=NULL){
            temp->next = a;
            a = a->next;
            temp = temp->next;
        }
        while(b!=NULL){
            temp->next = b;
            b = b->next;
            temp = temp->next;
        }
        return x->next;
    }
    ListNode *mergeSort(ListNode *head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *x = prev->next;
        prev->next = NULL;
        ListNode *left = head;
        left = mergeSort(left);
        x = mergeSort(x);
        return merge(left,x);

    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};