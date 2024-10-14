class Solution {
public:
    int solve(vector<int> &piles,int &n,int &h){
        int s =0;
        for(auto it : piles){
            s += (it-1)/n;
            s++;
        }
        return s;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = piles[0];
        for(int i =0;i<n;i++) maxi = max(maxi,piles[i]);
        if(n == h) return maxi;
        int l = 1,r = maxi;
        while(l < r){
            int mid = l + (r-l)/2;
            int l = solve(piles,mid,h);
            if(l <= h) r = mid;
            else l = mid+1;
        }
        return l;
    }
};