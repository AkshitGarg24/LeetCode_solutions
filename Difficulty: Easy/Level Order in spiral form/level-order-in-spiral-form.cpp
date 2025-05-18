//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after splitting by space
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

/* A binary tree node has data, pointer to left child
   and a pointer to right child
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class ListNode {
public:
    ListNode *next;
    Node* data;
    
    ListNode(Node* x){
        next = NULL;
        data = x;
    }
};

class LinkedList {
public:
    ListNode *head;
    ListNode *tail;

    LinkedList(){
        head = NULL;
        tail = NULL;
    }

    ListNode* LinkedListHead(){
        return head;
    }

    void insertAtHead(Node* x){
        if (!x) return;
        if (!head){
            head = tail = new ListNode(x);
            return;
        }
        ListNode *temp = new ListNode(x);
        temp->next = head;
        head = temp;
    }

    void insertAtTail(Node* x){
        if (!x) return;
        if (!tail){
            head = tail = new ListNode(x);
            return;
        }
        tail->next = new ListNode(x);
        tail = tail->next;
    }
};

class Solution {
public:
    vector<int> findSpiral(Node* root) {
        vector<int> ans;
        if (!root) return ans;

        LinkedList l;
        l.insertAtHead(root);
        int level = 0;

        ListNode* head = l.LinkedListHead();
        while (head) {
            LinkedList temp;
            while (head) {
                Node* current = head->data;
                ans.push_back(current->data);

                if (level % 2 == 0) {
                    temp.insertAtHead(current->right);
                    temp.insertAtHead(current->left);
                } else {
                    temp.insertAtHead(current->left);
                    temp.insertAtHead(current->right);
                }

                head = head->next;
            }
            level++;
            head = temp.LinkedListHead();
        }

        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    Solution sol; // Create Solution object
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        // Call the findSpiral function from Solution class
        vector<int> vec = sol.findSpiral(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends