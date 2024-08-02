class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        int end = INT_MIN;
        for(int i=0;i<n;i++){
            if(end<=intervals[i][0]){
                end = intervals[i][1];
                continue;
            } else {
                ans++;
            }
        }
        return ans;
    }
};