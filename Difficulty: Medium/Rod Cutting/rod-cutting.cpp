//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int check(vector<int> &price,int n,vector<int> &dp){
        if(n<=0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans = INT_MIN;
        for(int i=0;i<price.size();i++){
            int a = 0;
            if(n-i-1>=0){
                a = price[i] + check(price,n-i-1,dp);
                ans = max(ans,a);
            }
        }
        return dp[n] = ans;
    }
    int cutRod(vector<int> &price) {
        vector<int> dp(price.size()+1,-1);
        return check(price,price.size(),dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends