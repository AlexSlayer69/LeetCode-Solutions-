class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(),c = 0;
        unordered_map<string, int> mp;

        for(int i = 0;i<n;i++) {
            string s = "";
            for(int j = 0;j<n;j++){
                s += to_string(grid[i][j]);
                s += ",";
            }
            mp[s]++;
        }

        for(int i = 0;i<n;i++) {
            string s = "";
            for(int j = 0;j<n;j++){
                s += to_string(grid[j][i]);
                s += ",";
            }
            if(mp.find(s) != mp.end()) c += mp[s];
        }

        return c;
    }
};