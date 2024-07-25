class Solution {
public:
    void merge(vector<int> &nums,int l, int mid,int h){
        vector<int> temp;
        int i = l,j = mid+1;
        while(i<=mid && j<=h){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }
         while (i <= mid) {
            temp.push_back(nums[i++]);
        }
        while (j <= h) {
            temp.push_back(nums[j++]);
        }
        for (int k = 0; k < temp.size(); k++) {
            nums[l + k] = temp[k];
        }
    }
    void mergeSort(vector<int> &nums,int l, int h){
        if(l>=h){
            return;
        }
        int mid = l + (h-l)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,h);
        merge(nums,l,mid,h);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};