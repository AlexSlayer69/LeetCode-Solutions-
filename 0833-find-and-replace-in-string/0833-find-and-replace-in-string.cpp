class Solution {
public:
    string findReplaceString(string S, vector<int>& indices, vector<string>& sources, vector<string>& targets) {

        vector<pair<int, int>> sortedIndices;
        set<int> indexProcessed;
        for (int i = 0 ; i < indices.size(); i++)
            sortedIndices.push_back({indices[i], i});
        sort(rbegin(sortedIndices), rend(sortedIndices));
        for (auto ind : sortedIndices) {
            int i = ind.first;
            string s = sources[ind.second], t = targets[ind.second];
            if (indexProcessed.find(i) == indexProcessed.end() 
            && S.substr(i, s.length()) == s) {
                indexProcessed.insert(i);
                S = S.substr(0, i) + t + S.substr(i + s.length());
            }
        }
        return S;
    }
};