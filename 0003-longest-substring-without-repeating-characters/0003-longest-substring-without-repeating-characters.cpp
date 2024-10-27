class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> st;
        int j = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(st.count(s[i])){
                while(st.count(s[i])){
                    st.erase(s[j++]);
                }
            }
            st.insert(s[i]);
            //cout << i << " " << j << endl;
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};