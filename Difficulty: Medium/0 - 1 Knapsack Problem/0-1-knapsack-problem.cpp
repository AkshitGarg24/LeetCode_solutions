//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int check(int capacity,vector<int> &val,vector<int> &wt,vector<vector<int>> &dp,int i){
        if(i==val.size() || capacity==0){
            return 0;
        }
        if(dp[i][capacity]!=-1){
            return dp[i][capacity];
        }
        int take = INT_MIN, nottake;
        nottake = check(capacity,val,wt,dp,i+1);
        if(capacity>=wt[i]){
            take = val[i] + check(capacity-wt[i],val,wt,dp,i+1);
        }
        return dp[i][capacity] = max(take,nottake);
    }
    
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        vector<vector<int>> dp(val.size()+1,vector<int> (capacity+1,-1));
        return check(capacity,val,wt,dp,0);
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