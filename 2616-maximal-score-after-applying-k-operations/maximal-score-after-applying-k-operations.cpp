class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long int ans = 0;
        multiset<int,greater<int>> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        for(int i=0;i<k;i++){
            int x = *s.begin();
            ans += x;
            s.erase(s.find(x));
            int y = ceil((double)x/3);
            s.insert(y);
        }
        return ans;
    }
};