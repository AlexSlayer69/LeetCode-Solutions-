class Solution {
public:


    int trap(vector<int>& height) {
        int l=0,r = height.size()-1,sum = 0;
        int lmax = height[l], rmax = height[r];
        while(l <= r){
            if(lmax <= rmax){
                lmax = max(lmax,height[l]);
                sum += (lmax - height[l++]);
            }
            else{
                rmax = max(rmax,height[r]);
                sum += (rmax - height[r--]);
            }
        }
        return sum;
    }
};