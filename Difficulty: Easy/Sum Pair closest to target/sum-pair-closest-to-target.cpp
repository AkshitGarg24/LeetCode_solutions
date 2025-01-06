//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        if(arr.size()<=1){
            return {};
        }
        sort(arr.begin(),arr.end());
        int i = 0;
        int j = arr.size()-1;
        int x, y ;
        int cnt = INT_MAX;
        while(i<j){
            if(arr[i]+arr[j]==target){
                return {arr[i],arr[j]};
            } else if(arr[i]+arr[j]<target){
                if(abs(arr[i]+arr[j]-target)<cnt){
                    cnt = abs(arr[i]+arr[j]-target);
                    x = i, y = j;
                }
                i++;
            } else {
                if(abs(arr[i]+arr[j]-target)<cnt){
                    cnt = abs(arr[i]+arr[j]-target);
                    x = i, y = j;
                }
                j--;
            }
        }
        return {arr[x],arr[y]};
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends