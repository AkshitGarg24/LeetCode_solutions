class Solution {
public:
    int climbStairs(int n) {
        if(n<=2){
            return n;
        }
        int a = 1;
        int b = 2;
        int ans;
        for(int i=3;i<=n;i++){
            ans = a+b;
            a = b;
            b = ans;
        }
        return ans;
    }
};