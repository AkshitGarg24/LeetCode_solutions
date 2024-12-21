class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(),-1);
        int x = INT_MIN;
        for(int i=0;i<nums.size();i++){
            x = max(x,nums[i]);
        }
        int i = 0;
        stack<int> st;
        while(true){
            if(i>=nums.size() && !st.empty() && nums[st.top()]==x){
                break;
            }
            while(!st.empty() && nums[i%nums.size()]>nums[st.top()]){
                ans[st.top()] = nums[i%nums.size()];
                st.pop();
            }
            st.push(i%nums.size());
            i++;
        }
        return ans;
    }
};