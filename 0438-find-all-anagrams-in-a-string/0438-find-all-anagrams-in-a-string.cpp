class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
         if(p.length()>s.length())return {};
        int n=s.length(),pl=p.length();
        vector<int>map1(26,0),map2(26,0),ans;
        for(int i=0;i<pl;i++){
            map1[p[i]-'a']++;
            map2[s[i]-'a']++;
        }
        if(map1==map2)ans.push_back(0);
        for(int i=1;i<=n-pl;i++){
            map2[s[i+pl-1]-'a']++;
            map2[s[i-1]-'a']--;
            if(map1==map2)ans.push_back(i);
        }
        return ans;
    }
};