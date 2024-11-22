//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int optCost(int freq[],int i,int j,vector<vector<int>> &dp){
        if(j<i){
            return 0;
        }
        if(j==i){
            return freq[i];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a = 0;
        for(int x=i;x<=j;x++){
            a += freq[x];
        }
        int ans = INT_MAX;
        for(int r=i;r<=j;r++){
            int b = optCost(freq,i,r-1,dp) + optCost(freq,r+1,j,dp);
            ans = min(ans,b);
        }
        return dp[i][j] = ans+a;
    }
    
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return optCost(freq,0,n-1,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends