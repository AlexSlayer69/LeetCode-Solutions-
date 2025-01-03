class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int N = nums.size();
        vector<int> diff(N+1);
        

        for (int i = 0; i < N; i++) {
            int low = (i + 1) % N; 

          
            int high = (i - nums[i] + N) % N;
            if (low <= high) {
                diff[low]++;
                diff[high + 1]--;
            } else {
                diff[0]++;
                diff[high + 1]--;
                diff[low]++;
                diff[N]--;
            }
        }

        for (int i = 1; i < N; i++) {
            diff[i] += diff[i-1];
        }
        return max_element(diff.begin(), diff.end()) - diff.begin();
    }
};