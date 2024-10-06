class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n =nums.size();
        int j = -1,k=-1;
        for(int i = 0;i<n;i++){
            if(nums[i] == 0){
                j++;
                swap(nums[j],nums[i]);
                k++;
                if(k!=j){
                swap(nums[k],nums[i]);
                }
            }
            else if(nums[i] == 1){
                k++;
                swap(nums[k],nums[i]);
            }
            else if(nums[i] == 2) continue;
        }
    }
};