class Solution {
public:
    int nthUglyNumber(int n) {
        int c = 1;
        priority_queue<long long,vector<long long >,greater<long long>> pq;
        set<long long> s;
        s.insert(1);
        pq.push(1);
        while(c < n){
            long long el = pq.top();
            pq.pop();
            if(s.count(el*2) == 0){
                pq.push(el*2);
                s.insert(el*2);
            }
            if(s.count(el*3) == 0){
                pq.push(el*3);
                s.insert(el*3);
            }
            if(s.count(el*5) == 0){
                pq.push(el*5);
                s.insert(el*5);
            }
            c++;
        }
        return pq.top();
    }
};