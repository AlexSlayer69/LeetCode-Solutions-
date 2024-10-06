class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> ans;
        int n1 = nums1.size(),n2 = nums2.size();
        for(auto k1 : nums1) ans.push_back(k1);
        for(auto k2 : nums2) ans.push_back(k2);

        sort(ans.begin(),ans.end());

        int m = ans.size();
        if(m%2==0) return (ans[m/2]+ans[(m-2)/2])/2.0;
        
        return ans[m/2]; 
    }
};