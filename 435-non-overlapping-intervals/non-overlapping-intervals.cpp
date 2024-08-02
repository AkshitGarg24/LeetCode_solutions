class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n = intervals.size();
        int end = intervals[0][1];
        int ans = 0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<end){
                ans++;
            } else {
                end = intervals[i][1];
            }
        }
        return ans;
    }
};