//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            int j = i+1, k = arr.size()-1;
            while(j<k){
                if(arr[i]+arr[j]+arr[k]==target){
                    int a = 0,b = 0, x = j,y = k;
                    while(j<=k && arr[j]==arr[x]){
                        a++;
                        j++;
                    }
                    while(j<=k && arr[k]==arr[y]){
                        b++;
                        k--;
                    }
                    if(arr[x]==arr[y]){
                        ans += a*(a-1)/2;
                    } else {
                        ans += a*b;
                    }
                    
                } else if (arr[i]+arr[j]+arr[k]>target){
                    k--;
                } else {
                    j++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends