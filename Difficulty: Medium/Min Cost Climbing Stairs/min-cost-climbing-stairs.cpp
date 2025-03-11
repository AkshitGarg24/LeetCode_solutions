//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int totalCost(vector<int> &cost, int x,vector<int> &dp){
        if(x<0){
            return 0;
        }
        if(dp[x]!=-1){
            return dp[x];
        }
        int ans = 0;
        ans += cost[x] + min(totalCost(cost,x-1,dp),totalCost(cost,x-2,dp));
        return dp[x] = ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        vector<int> dp(cost.size(),-1);
        return totalCost(cost,cost.size()-1,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends