class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        if(n == 0) return ans;
        int st = nums[0];
        for(int i = 1;i<n;i++){
            if(nums[i] != nums[i-1]+1){
                string s;
                if(st != nums[i-1])
                    s = to_string(st) + "->" + to_string(nums[i-1]);
                else s = to_string(st);
                ans.push_back(s);
                st = nums[i];     
            }
        }
        
        string s;
        if(st != nums[n-1])
            s = to_string(st) + "->" + to_string(nums[n-1]);
        else s = to_string(st);
        ans.push_back(s);

        return ans;
    }
};