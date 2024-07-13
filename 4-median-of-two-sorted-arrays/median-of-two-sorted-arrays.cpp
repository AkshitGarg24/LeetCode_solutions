class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int l = 0;
        int h = nums1.size();
        int n;
        if((nums1.size()+nums2.size())%2==0){
            n = (nums1.size()+nums2.size())/2;
        }
        else{
            n = (nums1.size()+nums2.size())/2 + 1;
        }        
        while(l<=h){
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int h1 = INT_MAX;
            int h2 = INT_MAX;
            int mid = l + (h-l)/2;
            if(mid-1>=0){
                l1 = nums1[mid-1];
            }
            if(n-mid-1>=0){
                l2 = nums2[n-mid-1];
            }
            if(mid<nums1.size()){
                h1 = nums1[mid];
            }
            if(n-mid<nums2.size()){
                h2 = nums2[n-mid];
            }
            if(l1<=h2 && l2<=h1){
                if((nums1.size()+nums2.size())%2==0){
                    return (double)((double)max(l1,l2)+(double)min(h1,h2))/2;
                }
                else{
                    return (double)max(l1,l2);
                }
                
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