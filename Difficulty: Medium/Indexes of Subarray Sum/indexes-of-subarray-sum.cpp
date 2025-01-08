//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        vector<int> ans = {-1};
        unordered_map<int,int> m;
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            if(sum==target){
                ans = {1,i+1};
                break;
            }
            if(m.find(sum-target)!=m.end()){
                ans = {m[sum-target]+2,i+1};
                break;
            }
            m[sum] = i;
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
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends