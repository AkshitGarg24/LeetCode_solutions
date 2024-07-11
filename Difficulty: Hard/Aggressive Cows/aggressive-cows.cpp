//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool func(vector<int> &nums, int mid, int k){
        k--;
        int prev = nums[0];
        int i = 1;
        while(i<nums.size()){
            if(k==0){
                return true;
            }
            if(nums[i]-prev>=mid){
                k--;
                prev = nums[i];
            }
            i++;
        }
        return k==0;
    }
    int solve(int n, int k, vector<int> &nums) {
        sort(nums.begin(),nums.end());
        int l = 1;
        int h = nums[nums.size()-1] - nums[0];
        while(l<=h){
            int mid = l + (h-l)/2;
            if(func(nums,mid,k)==true){
                l = mid+1;
            }
            else {
                h = mid-1;
            }
        }
        return h;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends