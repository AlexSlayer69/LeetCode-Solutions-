class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        
        vector<string> tokens;
        stringstream ss(text);
        string token;

        while (getline(ss, token, ' ')) {
            tokens.push_back(token);
        }

        
        vector<string> result;
        for (size_t i = 0; i + 2 < tokens.size(); ++i) {
            if (tokens[i] == first && tokens[i + 1] == second) {
                result.push_back(tokens[i + 2]);
            }
        }

        return result;
    }
};