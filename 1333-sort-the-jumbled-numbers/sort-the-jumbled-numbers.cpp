class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b){
        return a.second<b.second;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> x(n);
        for(int i=0;i<n;i++){
            int a = nums[i];
            int b = 0;
            int ten = 1;
            if(a==0){
                b += ten*(mapping[a]);
            }
            while(a>0){
                b += ten*(mapping[a%10]);
                a = a/10;
                ten *= 10;
            }
            x[i] = {nums[i],b};
        }
        sort(x.begin(),x.end(),cmp);
        for(int i=0;i<n;i++){
            nums[i] = x[i].first;
        }
        return nums;
    }
};