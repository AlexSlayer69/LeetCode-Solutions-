class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) mp[row[i]] = i;

        int ans = 0;
        for(int i = 0; i < n - 1; i += 2){
            int partner = (row[i]%2==0 ? row[i]+1 : row[i]-1);
            if(row[i+1]!=partner){ 
                int j = mp[partner]; 
                swap(row[i+1],row[j]);
                mp[row[j]]=j;
                ans++;
            }
        }
        return ans;
    }
};