class Solution {
public:
    int func(vector<int> &piles, int mid, int x){
        int ans = 0;
        for(int i=0;i<piles.size();i++){
            ans += ceil((double)piles[i]/mid);
            if(ans>x){
                return INT_MAX;
            }
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int x) {
        int abc = *max_element(piles.begin(),piles.end());
        int ans;
        int l = 1;
        int h = abc;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(func(piles,mid,x)<=x){
                ans = mid;
                h = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return ans;
    }
};