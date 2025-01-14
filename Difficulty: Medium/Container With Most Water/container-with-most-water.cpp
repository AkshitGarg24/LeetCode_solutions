//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;

        while (left < right) {
            int h = min(height[left], height[right]);
            max_water = max(max_water, h * (right - left));

            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_water;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends