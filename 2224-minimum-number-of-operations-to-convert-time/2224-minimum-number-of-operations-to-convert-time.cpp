class Solution {
public:
    int convertTime(string cu, string co) {
        int cur = stoi(cu.substr(0,2))*60;
        int tar = stoi(co.substr(0,2))*60;
        cur += stoi(cu.substr(3));
        tar += stoi(co.substr(3));
        int ans =0;
        int arr[] = {60,15,5,1};
        for(auto it: arr){
            while(cur<= tar&& cur+it<=tar){
                cur += it;
                cout<<cur<<" ";
                ans++;
            }
        }
        return ans;
    }
};