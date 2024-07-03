class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        long i = 0;
        while(i<nums.size()){
            long j = i+1;
            while(j<nums.size()){
                long k = j+1;
                long l = nums.size()-1;
                while(k<nums.size() && k<l){
                    if((long)nums[k]+(long)nums[l]==(target-((long)nums[i]+(long)nums[j]))){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        long a = nums[k];
                        long b = nums[l];
                        while(k<nums.size() && nums[k]==a){
                            k++;
                        }
                        while(l>j && nums[l]==b){
                            l--;
                        }
                    }
                    else if((long)nums[k]+(long)nums[l]<(target-((long)nums[i]+(long)nums[j]))){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
                long c = nums[j];
                while(j<nums.size() && nums[j]==c){
                    j++;
                }
            }
            long d = nums[i];
            while(i<nums.size() && nums[i]==d){
                i++;
            }
        }
        return ans;
    }
};