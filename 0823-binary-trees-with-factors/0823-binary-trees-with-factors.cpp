class Solution {
public:
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,long long>mp;
        mp[arr[0]]=1;
        
        for(int ind=1;ind<arr.size();ind++){
            long long cnt=1;
            for(int i=0;i<=ind;i++){
                if(arr[ind]%arr[i]==0&&mp.find(arr[ind]/arr[i])!=mp.end()){
                    cnt+=mp[arr[i]]*mp[arr[ind]/arr[i]];
                }
            }
            mp[arr[ind]]=cnt;
        }

        long long sum=0;
        long long mod=1e9+7;
        for(auto x:mp){
            sum+=x.second;
            sum=sum%mod;
        }
        return sum;

    }
};