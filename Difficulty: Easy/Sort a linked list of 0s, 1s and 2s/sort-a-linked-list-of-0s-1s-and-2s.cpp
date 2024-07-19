//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        Node *zero = new Node(-1);
        Node *one = new Node(-1);
        Node *two = new Node(-1);
        Node *zerotemp = zero;
        Node *onetemp = one;
        Node *twotemp = two;
        Node *temp = head;
        while(temp!=NULL){
            if(temp->data==0){
                zerotemp->next = new Node(0);
                zerotemp = zerotemp->next;
            }
            if(temp->data==1){
                onetemp->next = new Node(1);
                onetemp = onetemp->next;
            }
            if(temp->data==2){
                twotemp->next = new Node(2);
                twotemp = twotemp->next;
            }
            temp = temp->next;
        }
        Node *ans = new Node(-1);
        temp = ans;
        if(zero->next!=NULL){
            temp->next = zero->next;
            temp = zerotemp;
        }
        if(one->next!=NULL){
            temp->next = one->next;
            temp = onetemp;
        }
        if(two->next!=NULL){
            temp->next = two->next;
            temp = twotemp;
        }
       return ans->next; 
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends