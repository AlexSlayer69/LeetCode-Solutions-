class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double,int>> workers;
        for(int i =0;i<n;i++) workers.push_back({wage[i]/(double)quality[i],quality[i]});
        sort(workers.begin(),workers.end());
        int sumq = 0;
        double sum = DBL_MAX;
        priority_queue<int> maxHeap;
        for(auto it : workers){
            double d = it.first;
            sumq += it.second;
            maxHeap.push(it.second);
            if(maxHeap.size() >  k){
                sumq -= maxHeap.top();
                maxHeap.pop();
            }
            if(maxHeap.size() == k){
                sum = min(sumq*ratio,sum);
            }
        }
        return sum;
    }
};