class Solution {
public:
    vector<int> constructRectangle(int area) {
        int i = 0;
        for(i = floor(sqrt(area));area%i != 0;i++);
        vector<int> v = {i,area/i};
        sort(v.begin(),v.end(),greater<int>());
        return v;
    }
};