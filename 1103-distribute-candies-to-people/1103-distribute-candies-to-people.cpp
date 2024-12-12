class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int i=0, c = 0;
        vector<int>arr(num_people,0);
        while(candies){
            arr[i++ %arr.size()] += min(++c,candies);
            candies -= min(c,candies);
        }
        return arr;
    }
};