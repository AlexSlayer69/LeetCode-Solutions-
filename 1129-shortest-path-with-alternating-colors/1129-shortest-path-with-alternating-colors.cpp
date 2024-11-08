class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> radj(n);
        vector<vector<int>> badj(n);
        for(int i =0; i < redEdges.size();i++){
            radj[redEdges[i][0]].push_back(redEdges[i][1]);
            //radj[redEdges[i][1]].push_back(redEdges[i][0]);
        }
        for(int i =0; i < blueEdges.size();i++){
            badj[blueEdges[i][0]].push_back(blueEdges[i][1]);
            //badj[blueEdges[i][1]].push_back(blueEdges[i][0]);
        }
        priority_queue<pair<int,pair<int,char>>,vector<pair<int,pair<int,char>>>,
                greater<pair<int,pair<int,char>>>> pq;
        vector<int> dist(n,INT_MAX);
        pq.push({0,{0,'0'}});
        dist[0] = 0;
        while(!pq.empty()){
            auto el = pq.top();
            pq.pop();
            if(el.second.second == 'r' || el.second.second == '0') {
                for(auto it : badj[el.second.first]){
                    if(el.first + 1 < dist[it]){
                        dist[it] = el.first+1;
                        pq.push({dist[it],{it,'b'}});
                    }
                }
            }
            if(el.second.second == 'b' || el.second.second == '0') {
                for(auto it : radj[el.second.first]){
                    if(el.first + 1 < dist[it]){
                        dist[it] = el.first+1;
                        pq.push({dist[it],{it,'r'}});
                    }
                }
            }
        }
        for(auto &it : dist){
            if (it == INT_MAX) it = -1;
        }
        return dist;
    }
};