class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        long long ans = w;
        priority_queue<long long>pq;
        vector<pair<int,int>>arr;
        for(int i = 0; i<n; i++){
            arr.push_back({capital[i], profits[i]});
        }
        sort(arr.begin(), arr.end());

        int i = 0;
        while((i < n) && (k > 0)){
            if(arr[i].first <= ans){
                pq.push(arr[i].second);
                i++;
            }
            else{
                if(pq.empty()) break;
                else{
                    ans += pq.top();
                    pq.pop();
                    k--;
                }
            }
        }

        while((k > 0) && (!pq.empty())){
            ans += pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};