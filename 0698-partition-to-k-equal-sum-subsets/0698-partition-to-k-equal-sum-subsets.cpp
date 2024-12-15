class Solution {
public:
 
bool posibl(vector<int>& nums,vector<bool>& vis,int k,long long int csum,long long int sum,int i){

        int n = nums.size();
        if(k==1) return 1;

        if(csum == sum) return posibl(nums,vis,k-1,0,sum,0);

        if(csum>sum) return 0;

            for(int j=i;j<n;j++)
            {
                if(!vis[j])
                {
                    vis[j] = 1;
                    if((csum+nums[j]<=sum) && (j+1<n) && posibl(nums,vis,k,csum+nums[j],sum,j+1))
                    return 1;
                    vis[j] = 0;
                }
            }
        
       
        return 0;
    }

bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();

        if(n<k) return 0;
        if(k==1) return 1;
       
        vector<bool> vis(n,0);
          
        long long int csum = 0;
        long long int sum = 0;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        
       if(sum%k==0)
       {
         
           return posibl(nums,vis,k,csum,sum/k,0);
       }

       return 0;
    }
};