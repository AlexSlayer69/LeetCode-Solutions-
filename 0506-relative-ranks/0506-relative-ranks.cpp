class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> pq;
        int n = score.size();
        for(int i = 0;i<n;i++){
            pq.push({score[i],i});
        }

        vector<string> answer(n,"");
        int sc = 1;
        while(!pq.empty()){
            auto [s,i] = pq.top();
            pq.pop();
            if(sc == 1) answer[i] = "Gold Medal";
            else if (sc == 2) answer[i] = "Silver Medal";
            else if(sc == 3) answer[i] = "Bronze Medal";
            else{
                answer[i] = to_string(sc);
            }
            sc++;
        }
        return answer;
    }
};