class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if(n1 != n2) return false;
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        vector<int> v1;
        vector<int> v2; 
        for(auto it : word1) m1[it]++;
        for(auto it : word2) m2[it]++;
        for(auto it : m1) {
            if(m2.find(it.first) == m2.end())
                return false;
        }
        for(auto it : m2) {
            if(m1.find(it.first) == m1.end())
                return false;
        }
        for(auto it : m1) v1.push_back(it.second);
        for(auto it : m2) v2.push_back(it.second);
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        return (v1 == v2) ? true : false;
    }
};