class Solution {
public:

// :) Pls Upvote!!
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 0; 

        for (auto it : weights) {
            l = max(l, it);  
            r += it;
        }

        while (l < r) {
            int mid = (l + r) / 2;
            int c = 1; 
            int cr = 0;

            for (auto it : weights) {
                if (cr + it > mid) {
                    c++;
                    cr = 0;
                }
                cr += it;
            }

            if (c > days) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};