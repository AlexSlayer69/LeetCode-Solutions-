class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 0;
        vector<int> ans(n,1);

        for(int i = 1;i<n;i++){
            if(ratings[i-1] < ratings[i]) ans[i] = ans[i-1]+1;
        }
        for(int i = n-1;i>0;i--){
            if(ratings[i-1] > ratings[i]) ans[i-1] = max(ans[i]+1,ans[i-1]);
        }
        
        for(auto i : ans) sum += i;
        return sum;
    }
};