class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans=0;
        int n = nums.size();
        vector<int> v(n, 0);
        for(int i=0; i<n; i++){
            int c = 0, k=i;
            while(!v[k]){
                v[k]=1;
                c++;
                k=nums[k];
            }
            ans=max(ans, c);
        }
        return ans;
    }
};