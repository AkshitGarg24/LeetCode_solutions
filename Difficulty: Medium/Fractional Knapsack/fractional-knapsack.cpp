//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    static bool cmp(Item &a, Item &b){
        double x = (double)a.value/a.weight;
        double y = (double)b.value/b.weight;
        return x>y;
    }
    double fractionalKnapsack(int w, Item arr[], int n) {
        sort(arr,arr+n,cmp);
        double ans = 0;
        for(int i=0;i<n;i++){
            int wt = min(w,arr[i].weight);
            ans += ((double)wt/arr[i].weight)*arr[i].value;
            w -= wt;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends