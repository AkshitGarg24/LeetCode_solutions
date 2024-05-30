class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0, maxlen = 0, count = 0;
        unordered_map<int,int> m;
        while(r<fruits.size()){
            if(m.count(fruits[r])==0){
                count++;
            }
            m[fruits[r]]++;
            if(count>2){
                m[fruits[l]]--;
                if(m[fruits[l]]==0){
                    count--;
                    m.erase(fruits[l]);
                }
                l++;
            }
            if(count<=2){
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};