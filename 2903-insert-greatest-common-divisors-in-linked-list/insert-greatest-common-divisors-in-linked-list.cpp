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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while (temp != NULL && temp->next != NULL) {
            int a = temp->val;
            int b = temp->next->val;
            int ans;
            while (a != 0 && b != 0) {
                if (a > b) {
                    a = a % b;
                } else {
                    b = b % a;
                }
            }
            if (a == 0) {
                ans = b;
            } else {
                ans = a;
            }
            ListNode* x = new ListNode(ans);
            x->next = temp->next;
            temp->next = x;
            temp = temp->next->next;
        }
        return head;
    }
};