class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count =0;
        for(int i=0;i<=s.length();i++)
        {
            string check  = s.substr(0,i);
            for(int j=0;j<words.size();j++)
            {
                if(check == words[j])
                {
                    count ++;
                }
            }
        }
        return count;
    }
};