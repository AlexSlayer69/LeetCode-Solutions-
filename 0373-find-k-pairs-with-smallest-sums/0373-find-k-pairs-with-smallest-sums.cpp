class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int,int>>> pq;
        for(int i=0; i<nums1.size(); ++i){
            pq.push({-1*(nums1[i]+nums2[0]), {i, 0}});
        }
        vector<vector<int>> ans;
        while(!pq.empty() && k){
            auto it=pq.top();
            int i=it.second.first;
            int j=it.second.second;
            pq.pop();
            ans.push_back({nums1[i],nums2[j]});
            if(j+1<nums2.size()){
                pq.push({-1*(nums1[i]+nums2[j+1]),{i,j+1}});
            }
            k--;
        }
        return ans;
    }
};