class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int l =0;
        int r = INT_MAX;
        int ans = -1;

        while(l <= r){
            int mid = (l+r)/2;
            int count = 0;
            int j = 0;
            for(int i =0;i<n;i++){
                if(bloomDay[i] <= mid) j++;
                else j = 0;
                if(j == k){
                    j = 0;
                    count++;
                }
            }
            if(count >= m){
                ans = mid;
                r = mid -1;
            }
            else l = mid +1;
        }
        return ans;
    }
};