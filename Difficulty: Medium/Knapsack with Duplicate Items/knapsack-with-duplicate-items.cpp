//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int check(vector<int> &val,vector<int> &wt,int capacity,vector<int> &dp){
        if(capacity<=0){
            return 0;
        }
        if(dp[capacity]!=-1){
            return dp[capacity];
        }
        int ans = INT_MIN;
        for(int i=0;i<val.size();i++){
            int a = 0;
            if(capacity>=wt[i]){
                a = val[i] + check(val,wt,capacity-wt[i],dp);
            }
            ans = max(ans,a);
        }
        return dp[capacity] = ans;
    }
    
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<int> dp(capacity+1,-1);
        return check(val,wt,capacity,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends