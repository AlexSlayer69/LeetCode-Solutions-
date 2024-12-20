class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();
        if(n<4) return false;
        distance.insert(distance.begin(),0);
        for(int i = 3;i<=n;i++){
            if(distance[i] >= distance[i-2] && distance[i-1] <= distance[i-3]) 
                return true;
            if(i >= 5){
                if(distance[i-1] >= distance[i-3] - distance[i-5] &&
                distance[i] >= distance[i-2] - distance[i-4] && 
                distance[i-1] <= distance[i-3] && distance[i-2] >= distance[i-4])
                    return true;
            }
        }
    return false;
    }
};