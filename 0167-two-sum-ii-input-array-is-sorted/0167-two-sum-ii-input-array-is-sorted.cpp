class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0;
        int r = n-1;
        
        vector<int> ans;

        while(l < r){
            int sum = numbers[l] + numbers[r];
            if(sum > target) r--;
            else if(sum < target) l++;
            else{
                ans.push_back(l+1);
                ans.push_back(r+1);
                return ans;
            }
        }
        return ans;
    }
};