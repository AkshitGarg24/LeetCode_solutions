class Solution {
public:
    int check(vector<int> &nums,int target,int i,map<pair<int,int>,int> &m){
        if(i==0){
            int ans = 0;
            int a = target-nums[0];
            if(a==0){
                ans++;
            }
            a = target + nums[0];
            if(a==0){
                ans++;
            }
            return ans;
        }
        if(m.find({i,target})!=m.end()){
            return m[{i,target}];
        }
        int a = check(nums,target-nums[i],i-1,m);
        int b = check(nums,target+nums[i],i-1,m);
        return m[{i,target}] = a+b;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>,int> m;
        return check(nums,target,nums.size()-1,m);
    }
};