class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> temp(nums.size()+1, 0);
        for(int i=0;i<queries.size();i++){
            temp[queries[i][0]]--;
            temp[queries[i][1]+1]++;
        }
        int x = 0;
        for(int i=0;i<nums.size();i++){
            x += temp[i];
            nums[i] += x;
            if(nums[i]>0){
                return false;
            }
        }
        return true;
    }
};