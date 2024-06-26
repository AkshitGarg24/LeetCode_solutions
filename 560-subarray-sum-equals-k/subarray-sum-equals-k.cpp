class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        map<int,int> m;
        int sum  = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum==k){
                count++;
            }
            if (m.find(sum-k)!=m.end()){
                count += m[sum-k];
            }
            m[sum]++;
        }
        return count;
    }
};