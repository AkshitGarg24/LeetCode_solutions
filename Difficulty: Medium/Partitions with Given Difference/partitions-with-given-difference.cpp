//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int check(vector<int> &arr,int d,int n,int cnt,int sum,vector<vector<int>> &dp){
        if(n==0){
            int ans = 0;
            int a = cnt;
            if(a-(sum-a)==d){
                ans++;
            }
            a += arr[n];
            if(a-(sum-a)==d){
                ans++;
            }
            return ans;
        }
        if(dp[n][cnt]!=-1){
            return dp[n][cnt];
        }
        int a = check(arr,d,n-1,cnt,sum,dp);
        int b = check(arr,d,n-1,cnt+arr[n],sum,dp);
        return dp[n][cnt] = a+b;
    }
  
    int countPartitions(vector<int>& arr, int d) {
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            sum+= arr[i];
        }
        vector<vector<int>> dp(arr.size(),vector<int> (sum+1,-1));
        return check(arr,d,arr.size()-1,0,sum,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends