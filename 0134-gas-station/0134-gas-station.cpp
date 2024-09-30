class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(),sum=0;
        for(int i = 0;i <n ;i++) sum += gas[i] - cost[i];;
        if(sum < 0) return -1;

        int ind = -1,max_tank = INT_MIN,diff = 0;

        for(int i = n-1;i >=0 ;i--){
            diff += (gas[i] - cost[i]);
            if(diff > max_tank){
                max_tank = diff;
                ind = i;
            }
        }
        return ind;
    }
};