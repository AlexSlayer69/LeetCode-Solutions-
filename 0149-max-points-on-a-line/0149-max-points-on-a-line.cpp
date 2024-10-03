class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1 || n == 0) return n;

        int mx = 0;

        for (auto p1 : points) {
            unordered_map<double, int> mp;
            for (auto p2: points) {
                double slope = INT_MIN;
                if (p1 == p2) continue;
                if (p1[0] != p2[0])      
                    slope = (double) (p2[1] - p1[1]) / (p2[0] - p1[0]);
                mp[slope]++;
                mx = max(mx, mp[slope]);
            }
        }

        return mx + 1;
    }
};