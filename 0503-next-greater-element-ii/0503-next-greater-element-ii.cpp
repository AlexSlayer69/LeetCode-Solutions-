class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        s.push(nums[n-1]);
        for(int i = 2*n-2;i>=n;i--){
            while(!s.empty() && s.top() <= nums[i%n]) {
                s.pop();
            }
            s.push(nums[i%n]);
        }
        vector<int> ans(n,0);
        for(int i = n-1;i>=0;i--){
            while(!s.empty() && s.top() <= nums[i]) s.pop();
            if(s.empty()) ans[i] = -1;
            else ans[i] = s.top();
            s.push(nums[i]);
        }
        return ans;
    }
};