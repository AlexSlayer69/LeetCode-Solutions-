class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(),prod = 1;
        int num_zeros = 0,ind_f = -1;
        vector<int> answer(n,0);
        for(int i =0;i<n;i++){
            if(nums[i] == 0){
                if(num_zeros == 0)
                    ind_f = i;
                num_zeros++;
            }
            else
                prod *= nums[i];
        }

        if(num_zeros == 0){
            for(int i=0;i<n;i++)
            answer[i] = prod/nums[i];    
        }    
        else if(num_zeros == 1) answer[ind_f] = prod;
        
        return answer;
    }
};