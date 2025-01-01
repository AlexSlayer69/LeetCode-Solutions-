class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> ans;
        int z=max(a,max(b,c));
        int x=min(a,min(b,c));
        int y=a+b+c-x-z;
        int d1=abs(x-y)-1;
        int d2= abs(z-y)-1;
        if(d1==0&&d2==0){
            ans.push_back(0);
        }
    else if (d1 <= 1 || d2 <= 1) {
            ans.push_back(1);
        } else {
            ans.push_back(2);
        }
        ans.push_back(d1+d2);
        return ans;
    }
};