class Solution {
public:
    static bool compare(vector<int> a, vector<int> b){
        if(a[0] < b[0]){
            return true;
        }
        else if(a[0] > b[0]) return false;
        else{
            return (a[1] <= b[1]) ? true : false;
        }
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),compare);
        int cnt = 1;
        int end = points[0][1];
        int tmp = 1;
        for(int i = 1;i<points.size();i++){
            if(points[i][0] > end){
                cnt++;
                tmp = 1;
                end = points[i][1];
            }
            else{
                end = min(end,points[i][1]);
                tmp++;
            }  
        }
        return cnt;
    }
};