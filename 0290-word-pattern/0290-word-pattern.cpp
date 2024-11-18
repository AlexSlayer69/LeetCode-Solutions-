class Solution {
public:

    string ext(string &s,int &j){
         string word;
        while(j<s.length() and s[j]!=' ') word.push_back(s[j++]);
        return word;
    }   

    bool wordPattern(string pattern, string s) {
        int i =0,j=0,c1= 0,c2 = 0;
        vector<int> v(26,0);
        unordered_map<string,int> mp;

        while(i < pattern.size() && j < s.length()){
            string word = ext(s,j);

            if(v[pattern[i] - 'a'] == 0) v[pattern[i] - 'a'] = ++c1;
            
            if(mp.find(word) == mp.end()) mp[word] = ++c2;

            if(v[pattern[i] - 'a'] != mp[word]) return false;
            i++;
            j++;
        }
        return (i >= pattern.size() && j >= s.length());
    }
};