class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>result;
        unordered_map<string,int>mp;

        istringstream iss(s1);
        istringstream is(s2);

        string word;

        while(iss >> word){
            mp[word]++;
        }

        while(is>>word){
            mp[word]++;
        }

        for(auto it:mp){
            if(it.second==1)
                result.push_back(it.first);
        }
        return result;
    }
};