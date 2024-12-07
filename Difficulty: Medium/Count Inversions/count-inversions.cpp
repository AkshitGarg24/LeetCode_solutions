//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    
    int mergeSort(vector<int> &arr,int l,int mid, int h){
        int ans = 0;
        vector<int> temp;
        int i = l, j = mid+1;
        while(i<=mid && j<=h){
            if(arr[i]>arr[j]){
                temp.push_back(arr[j]);
                j++;
                ans += mid-i+1;
            } else {
                temp.push_back(arr[i]);
                i++;
            }
        }
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=h){
            temp.push_back(arr[j]);
            j++;
        }
        for(int i=0;i<temp.size();i++){
            arr[l+i] = temp[i];
        }
        return ans;
    }
    
    int merge(vector<int> &arr,int l,int h){
        if(l>=h){
            return 0;
        }
        int mid = l+(h-l)/2;
        int a = merge(arr,l,mid);
        int b = merge(arr,mid+1,h);
        int c = mergeSort(arr,l,mid,h);
        return a+b+c;
    }
    
    int inversionCount(vector<int> &arr) {
        return merge(arr,0,arr.size()-1);
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends