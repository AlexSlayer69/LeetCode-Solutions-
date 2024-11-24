class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char,int> mp;
        int maxi = 0;
        int ans = 0;
        int l =0;
        for(int i = 0;i < n;i++){
            mp[s[i]]++;
            maxi = max(maxi,mp[s[i]]);
            int len = i-l+1;
            if(len - maxi > k){
                mp[s[l]]--;
                l++;
            }
            len = i-l+1;
            ans = max(len,ans);
        }
        return ans; 
    }
};