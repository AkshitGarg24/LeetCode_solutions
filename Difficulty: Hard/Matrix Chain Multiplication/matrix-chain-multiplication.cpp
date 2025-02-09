//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int check(vector<int> &arr,int i,int j,vector<vector<int>> &dp){
        if(i==j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k=i;k<j;k++){
            int steps = arr[i-1]*arr[k]*arr[j] + check(arr,i,k,dp) + check(arr,k+1,j,dp);
            ans = min(ans,steps);
        }
        return dp[i][j] = ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        vector<vector<int>> dp(arr.size(),vector<int> (arr.size(),-1));
        return check(arr,1,arr.size()-1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends