class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> cy(nums.begin(),nums.end());
        sort(cy.begin(),cy.end());
        for(int i =0,j=(n-1)/2+1,l=n-1;l>=0;l--){
            if(l%2) nums[l] = cy[j++];
            else nums[l] = cy[i++];
        }
    }
};