//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int at[], int dt[], int n)
    {
    	sort(at,at+n);
    sort(dt,dt+n);
    int i = 1;
    int j = 0;
    int ans = 1,count = 1;
    while(i<n && j<n){
        if(at[i]<=dt[j]){
            count++;
            i++;
        } else {
            count--;
            j++;
        }
        ans = max(ans,count);
    }
    return ans;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends