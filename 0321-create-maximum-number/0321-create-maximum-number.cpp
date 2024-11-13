class Solution {
public:
    vector<int> solve(vector<int> &nums, int k) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i) {
            while(!ans.empty() && ans.back() < nums[i] && k - ans.size() <= nums.size() - i - 1) {
                ans.pop_back();
            }
            if(ans.size() < k) ans.push_back(nums[i]);
        }
        return ans;
    }

    bool greater(vector<int> &v1, vector<int> &v2, int a, int b) {
        while(a < v1.size() || b < v2.size()) {
            if(a == v1.size()) return false;
            else if(b == v2.size()) return true;
            else if(v1[a] < v2[b]) return false;
            else if(v1[a] > v2[b]) return true;
            else ++a, ++b;
        }
        return true;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        for(int i = 0; i <= k; ++i) {
            int j = k - i;
            if(i > nums1.size() || j > nums2.size()) continue;
            vector<int> v1 = solve(nums1, i);
            vector<int> v2 = solve(nums2, k-i);

            vector<int> merged;
            int a = 0, b = 0;
            while(a < v1.size() || b < v2.size()) {
                if(a == v1.size()) merged.push_back(v2[b++]);
                else if(b == v2.size()) merged.push_back(v1[a++]);
                else if(v1[a] < v2[b]) merged.push_back(v2[b++]);
                else if(v1[a] > v2[b]) merged.push_back(v1[a++]);
                else if(greater(v1,v2,a,b)) merged.push_back(v1[a++]);
                else merged.push_back(v2[b++]);
            }

            if(ans < merged){
                ans = merged;
            }
        }
        return ans;        
    }
};