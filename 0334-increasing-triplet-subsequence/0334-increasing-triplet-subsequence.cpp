class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mini = INT_MAX;
        int second_min = INT_MAX;
        for(auto it : nums){
            if(it <= mini) mini = it;
            else if(it <= second_min) second_min = it;
            else return true;
        }
        return false;
    }
};