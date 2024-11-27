class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long maxi=0, sum=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<pair<int,int>> v;
        
        for(int i=0;i<nums1.size();i++) 
            v.push_back({nums2[i],nums1[i]});
        
        
        sort(v.begin(),v.end(),greater<pair<int,int>>());

        for(int i=0;i<nums1.size();i++){
            sum += v[i].second;
            pq.push(v[i].second);
            
            if(pq.size() == k){
                maxi = max(maxi,sum*v[i].first);
                sum-=pq.top();
                pq.pop();
            }
        }
        return maxi;
    }
};