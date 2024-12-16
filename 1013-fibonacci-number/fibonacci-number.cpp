class Solution {
public:
    int check(vector<int> &dp,int n){
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n] = check(dp,n-1) + check(dp,n-2);
    }

    int fib(int n) {
        vector<int> dp(n+1,-1);
        return check(dp,n);
    }
};