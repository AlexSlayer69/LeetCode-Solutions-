class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> pts(101,0);
        for(int i =0;i<nums.size();i++){
            for(int j = nums[i][0];j<=nums[i][1];j++){
                pts[j] = 1;
            }
        }
        int ans = 0;
        for(int i =1;i<101;i++){
            ans += pts[i];
        }
        return ans;
    }
};