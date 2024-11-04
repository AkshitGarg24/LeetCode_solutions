//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findSubArraySum(int k, vector<int> &nums) {
        int ans = 0;
        unordered_map<int,int> m;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum==k){
                ans++;
            }
            if(m.find(sum-k)!=m.end()){
                ans += m[sum-k];
            }
            m[sum]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.findSubArraySum(k, arr);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends