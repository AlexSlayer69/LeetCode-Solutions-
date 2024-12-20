class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), moves = 0;
        sort(nums.begin(), nums.end());
        int median = nums[n/2];
        for(int i=0; i<n; i++){
            moves += abs(nums[i] - median);
        }
        return moves;
    }
};