class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = (start^goal);
        int ans = 0;
        while(x>0){
            ans += (x&1);
            x = x>>1;
        }
        return ans;
    }
};