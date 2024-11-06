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
        for(int i=0;i<v.size()-1;i++){
            bool check = false;
            for(int j=0;j<v.size()-1;j++){
                if(v[j].first>v[j+1].first && v[j].second!=v[j+1].second){
                    return false;
                }
                if(v[j].first>v[j+1].first && v[j].second==v[j+1].second){
                    swap(v[j],v[j+1]);
                    check = true;
                }
            }
            if(check==false){
                return true;
            }
        }
        return true;
    }
};