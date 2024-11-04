/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        map<Node *,Node *> m;
        Node *x = new Node(head->val);
        Node *head2 = x;
        m[head] = x;
        Node *temp = head->next;
        while(temp){
            x->next = new Node(temp->val);
            m[temp] = x->next;
            temp = temp->next;
            x = x->next;
        }
        Node *temp1 = head;
        Node *temp2 = head2;
        while(temp1){
            if(temp1->random==NULL){
                temp2->random = NULL;
            } else {
                temp2->random = m[temp1->random];
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return head2;
    }
};