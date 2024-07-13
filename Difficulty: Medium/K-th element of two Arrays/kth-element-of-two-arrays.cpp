//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int nums1[], int nums2[], int n, int m, int k)
    {
        if(n>m){
            return kthElement(nums2,nums1,m,n,k);
        }
        int l = max(k-m,0);
        int h = min(k,n);
        while(l<=h){
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int h1 = INT_MAX;
            int h2 = INT_MAX;
            int mid = l + (h-l)/2;
            if(mid-1>=0){
                l1 = nums1[mid-1];
            }
            if(k-mid-1>=0){
                l2 = nums2[k-mid-1];
            }
            if(mid<n){
                h1 = nums1[mid];
            }
            if(k-mid<m){
                h2 = nums2[k-mid];
            }
            if(l1<=h2 && l2<=h1){
                return max(l1,l2);
            }
            else if(l2>h1){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends