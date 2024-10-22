//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int ans = 0;
        int cnt = 0;
        unordered_map<int,int> m;
        int l = 0, h = 0;
        while(h<arr.size()){
            if(m.find(arr[h])==m.end()){
                cnt++;
            }
            m[arr[h]]++;
            if(cnt>2){
                m[arr[l]]--;
                if(m[arr[l]]==0){
                    m.erase(arr[l]);
                    cnt--;
                }
                l++;
            }
            ans = max(ans,h-l+1);
            h++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends