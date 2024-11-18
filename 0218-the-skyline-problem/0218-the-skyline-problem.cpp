class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<int>> ans;
        int h;
        vector<int> temp;
        unordered_set<int> indexes;
        multiset<int,greater<int>> heights;
        for(int i =0;i< buildings.size();i++){
            pq.push({buildings[i][0],i});
            pq.push({buildings[i][1],i});
        }
        while(!pq.empty()){
            int el = pq.top().first;
            while(!pq.empty() && pq.top().first == el){
                int ind = pq.top().second;
                if(indexes.count(ind) == 1){
                    heights.erase(buildings[ind][2]);
                }
                else{
                    indexes.insert(ind);
                    heights.insert(buildings[ind][2]);
                }
                pq.pop();
            }
            if(ans.size() == 0 || h != *heights.begin()) {
                h = *heights.begin();
                temp = {el,h};
                ans.push_back(temp);
            }
        }
        return ans;
    }
};