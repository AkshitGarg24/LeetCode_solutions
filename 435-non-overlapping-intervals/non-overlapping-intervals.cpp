class Solution {
public:

    static bool cmp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        int prev = INT_MIN;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i][0]>=prev){
                prev = nums[i][1];
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};