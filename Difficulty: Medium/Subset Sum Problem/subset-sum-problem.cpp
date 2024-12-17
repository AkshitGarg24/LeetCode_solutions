//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    bool check(vector<int> &arr,int target, int n, vector<vector<int>> &dp){
        if(target==0){
            return true;
        }
        if(n==0){
            if(arr[n]==target){
                return true;
            } else {
                return false;
            }
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        bool a = check(arr,target,n-1,dp);
        bool b = false;
        if(target>=arr[n]){
            b = check(arr,target-arr[n],n-1,dp);
        }
        
        return dp[n][target] = (a||b);
    }
  
    bool isSubsetSum(vector<int>& arr, int target) {
        vector<vector<int>> dp(arr.size(),vector<int> (target+1,-1));
        return check(arr,target,arr.size()-1,dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends