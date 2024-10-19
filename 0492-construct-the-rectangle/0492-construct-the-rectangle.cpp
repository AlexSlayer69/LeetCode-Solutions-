class Solution {
public:
    vector<int> constructRectangle(int area) {
        int min = area-1;
        vector<int> ans = {area,1};
        for(int i = 1;i<=area/2;i++){
            if(area%i == 0) {
                if(abs(i - area/i) < min){
                    min = abs(i - area/i);
                    ans = {area/i,i};
                }
            }
        }
        return ans;
    }
};