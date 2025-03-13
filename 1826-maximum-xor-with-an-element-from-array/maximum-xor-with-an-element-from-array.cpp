class Node {
    vector<Node*> link;
    bool flag;
public:
    Node() {
        link = vector<Node*>(2, NULL);
        flag = false;
    }
    void setFlag() {
        flag = true;
    }
    bool containsKey(int bit) {
        return link[bit] != NULL;
    }
    void setKey(int bit, Node* m) {
        link[bit] = m;
    }
    Node* getKey(int bit) {
        return link[bit];
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(int num) {
        Node* x = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!x->containsKey(bit)) {
                x->setKey(bit, new Node());
            }
            x = x->getKey(bit);
        }
        x->setFlag();
    }
    int getMaxXOR(int num) {
        Node* x = root; 
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (x->containsKey(1 - bit)) {
                ans |= (1 << i);
                x = x->getKey(1 - bit);
            } else {
                x = x->getKey(bit);
            }
        }
        return ans;
    }
};

static bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
        Trie t;
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i); 
        }
        sort(queries.begin(), queries.end(), cmp);

        vector<int> ans(queries.size(), -1); 
        int x = 0;
        for (int i = 0; i < queries.size(); i++) {
            while (x < arr.size() && queries[i][1] >= arr[x]) {
                t.insert(arr[x]);
                x++;
            }
            if (x > 0) { 
                ans[queries[i][2]] = t.getMaxXOR(queries[i][0]);
            }
        }
        return ans;
    }
};