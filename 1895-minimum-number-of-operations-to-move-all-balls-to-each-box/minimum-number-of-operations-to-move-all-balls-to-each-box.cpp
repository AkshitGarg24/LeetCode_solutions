class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size());
        vector<int> temp;
        int x;
        for(int i=0;i<boxes.size();i++){
            if(boxes[i]=='1'){
                temp.push_back(i);
            }
        }
        for(int i=0;i<boxes.size();i++){
            x = 0;
            for(int j=0;j<temp.size();j++){
                x += abs(i-temp[j]);
            }
            ans[i] = x;
        }
        return ans;
    }
};