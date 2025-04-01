typedef long long ll;
class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        if(tasks.size()==1) return 1;
        map<int,ll> prev;   
        ll days=0;
        for(int i=0;i<tasks.size();i++){
            if(prev[tasks[i]]){
                days=max(prev[tasks[i]]+space+1,days+1);
                prev[tasks[i]]=days;
            }
            else{
                days++;
                prev[tasks[i]]=days;
            }
        }
        return days;
    }
};