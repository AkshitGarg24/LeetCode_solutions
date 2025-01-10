//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int ans = 1;
        unordered_map<char,int> m;
        int j = 0;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            while(m[s[i]]>1){
                m[s[j]]--;
                j++;
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends