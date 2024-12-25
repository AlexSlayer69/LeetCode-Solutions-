class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> cycle;
        int days = 0, maxGDay = 0;
        for(int i = 0; i < plantTime.size(); i++){
            cycle.push_back(make_pair(growTime[i], plantTime[i]));
        }
        
        sort(cycle.rbegin(), cycle.rend());
        
        for(int i = 0; i < cycle.size(); i++){
            days += cycle[i].second;
            maxGDay = max(maxGDay, days + cycle[i].first);     
        }
        
        return maxGDay;
        
    }
};