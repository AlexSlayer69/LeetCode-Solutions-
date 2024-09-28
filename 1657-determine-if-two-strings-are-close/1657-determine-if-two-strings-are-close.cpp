class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if(n1 != n2) return false;
        set<char> s1;
        set<char> s2;
        vector<int> v1(26,0);
        vector<int> v2(26,0); 
        s1.insert(word1.begin(),word1.end());
        s2.insert(word2.begin(),word2.end());
        if(s1 != s2) return false;
        for(int i = 0;i < n1;i++) v1[word1[i] - 'a']++;
        for(int i = 0;i < n2;i++) v2[word2[i] - 'a']++;
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if(v1 != v2) return false;
        return true;
    }
};