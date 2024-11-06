class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            int cnt = 0;
            int x = nums[i];
            while(x>0){
                cnt += (x&1);
                x = x>>1;
            }
            v.push_back({nums[i],cnt});
        }
        int a = INT_MIN, b = INT_MIN;
        int x = nums[0], y = nums[0];
        for(int i=1;i<nums.size();i++){
            if(v[i].second==v[i-1].second){
                x = min(x,v[i].first);
                y = max(y,v[i].first);
            } else {
                if(x<b){
                    return false;
                }
                a = x;
                b = y;
                x = v[i].first;
                y = v[i].first;
            }
        }
        if (x < b) {
            return false;
        }
        return true; 
    }
};