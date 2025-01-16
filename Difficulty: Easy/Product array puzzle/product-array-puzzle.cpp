//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        vector<int> ans(arr.size(),0);
        int product = 1,zeros = 0,idx = -1;
        
        for(int i=0;i<arr.size();i++){
            if(!arr[i]){
                zeros++;
                idx = i;
                continue;
            }
            product *= arr[i];
        }
        if(zeros>1){
            return ans;
        }
        if(zeros==1){
            ans[idx] = product;
            return ans;
        }
        for(int i=0;i<arr.size();i++){
            ans[i] = product/arr[i];
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
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends