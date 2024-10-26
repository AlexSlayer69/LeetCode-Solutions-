class Solution {
public:
    static bool compare(vector<int> a, vector<int> b){
        return (a[1] < b[1]);
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),compare);
        int cnt = 1;
        int end = points[0][1];
        for(int i = 1;i<points.size();i++){
            if(points[i][0] > end){
                cnt++;
                end = points[i][1];
            }
        }
        return cnt;
    }
};