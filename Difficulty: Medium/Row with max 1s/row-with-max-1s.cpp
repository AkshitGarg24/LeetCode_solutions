//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > arr) {
        int ans = 0;
        int idx = -1;
        for(int i=0;i<arr.size();i++){
            int l = 0;
            int h = arr[i].size()-1;
            while(l<=h){
                int mid = l+(h-l)/2;
                if(arr[i][mid]==1){
                    if(arr[i].size()-mid>ans){
                        ans = arr[i].size()-mid;
                        idx = i;
                    }
                    h = mid-1;
                }
                else {
                    l = mid+1;
                }
            }
        }
        return idx;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends