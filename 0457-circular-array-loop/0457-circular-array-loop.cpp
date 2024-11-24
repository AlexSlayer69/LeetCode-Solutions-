class Solution {
public:
    vector<int> cp;
    int next(int i){
        int n = cp.size();
        return ((i + cp[i]%n) + n)%n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        cp = nums;
        for(int i = 0;i < n;i++){
            int slow = i;
            int fast = next(i);
            while(nums[slow] * nums[fast] > 0 && nums[slow]*nums[next(fast)] > 0){
                if (slow == fast) {
                    if (slow != next(slow)) {
                        return true;
                    }
                    break;
                }
                slow = next(slow);
                fast = next(next(fast));
            }
        }
        return false;
    }
};