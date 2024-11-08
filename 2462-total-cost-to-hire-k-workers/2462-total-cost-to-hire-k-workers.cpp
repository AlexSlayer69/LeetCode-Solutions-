class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int i = 0;
        int j = costs.size();
        for(i = 0;i < candidates;i++){
            pq.push({costs[i],0});
            pq.push({costs[--j],1});
        }
        long long sum = 0;
        while(k > 0 && i < j){
            //cout << i << " " <<  j << " " << pq.top().first << endl;
            sum += pq.top().first;
            if(pq.top().second == 0){
                pq.pop();
                pq.push({costs[i++],0});
            }
            else if(pq.top().second == 1){
                pq.pop();
                pq.push({costs[--j],1});
            }
            k--;
        }
        if(k == 0) return sum;
        while(k--){
            sum += pq.top().first;
            pq.pop();
        }
        return sum;
    }
};