class Solution {
    bool check(vector<int> &nums, vector<vector<int>> &queries, int mid){
        vector<int> temp(nums.size()+1,0);
        for(int i=0;i<=mid;i++){
            temp[queries[i][0]] -= queries[i][2];
            temp[queries[i][1]+1] += queries[i][2];
        }
        int x = 0;
        for(int i=0;i<nums.size();i++){
            x += temp[i];
            int y = nums[i] + x;
            if(y>0){
                return false;
            }
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        bool flag = true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                flag = false;
                break;
            }
        }
        if(flag){
            return 0;
        }
        int l = 0, h = queries.size()-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(check(nums,queries,mid)){
                h = mid-1;
            } else {
                l = mid+1;
            }
        }
        if(l>=queries.size()){
            return -1;
        }
        return l+1;
    }
};