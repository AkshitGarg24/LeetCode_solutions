//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int ones = 0, zeros = 0,ans = 0;
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++){
            if(arr[i]){
                ones++;
            } else {
                zeros++;
            }
            if(ones==zeros){
                ans = max(ans,i+1);
            } else {
                if(m.find(ones-zeros)!=m.end()){
                    ans = max(ans,i-m[ones-zeros]);
                }
            }
            if(m.find(ones-zeros)==m.end()){
                m[ones-zeros] = i;
            }
            
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends