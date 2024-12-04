class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        
        int i, n = mat.size();
        int low = mat[0][0], high = mat[n-1][n-1], mid, count = 0, ans;
        
        while(low <= high)
        {
            mid = low + (high - low)/2;
            count = 0;
            for(i=0;i<n;i++)
                count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            if(count >= k)
            {
                high = mid - 1;
                ans = mid;
            }          
            else
                low = mid + 1;
        }
        return ans;
    }
};