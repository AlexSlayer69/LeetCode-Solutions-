class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }
        stack<int> s;
        vector<int> mina(n);
        mina[0] = nums[0];
        for(int i =1;i<n;i++){
            mina[i] = min(mina[i-1],nums[i]);
        }
        for (size_t j = n-1; j > 0; j--) {
            if(nums[j] <= mina[j]) continue;
            while(!s.empty() && s.top() <= mina[j]) s.pop();
            if(!s.empty() && s.top() < nums[j]) return true;
            s.push(nums[j]);
        }
        return false;
    }
};