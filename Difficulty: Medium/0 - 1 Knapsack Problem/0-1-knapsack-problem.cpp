//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    void check(vector<pair<int,int>> &v,int &ans,int i,int cntcapa,int cntvala,int capacity){
        if(cntcapa>capacity){
            return;
        }
        
        if(i==v.size()){
            ans = max(ans,cntvala);
            return;
        }
        
        cntcapa += v[i].second;
        cntvala += v[i].first;
        check(v,ans,i+1,cntcapa,cntvala,capacity);
        cntcapa -= v[i].second;
        cntvala -= v[i].first;
        check(v,ans,i+1,cntcapa,cntvala,capacity);
        return;
    }
      
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        vector<pair<int,int>> v;
        for(int i=0;i<val.size();i++){
            v.push_back({val[i],wt[i]});
        }
        int ans = INT_MIN;
        int i = 0;
        int cntcapa = 0;
        int cntvala = 0;
        check(v,ans,i,cntcapa,cntvala,capacity);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends