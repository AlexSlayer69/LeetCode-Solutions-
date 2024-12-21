class Solution {
public:
    int DFS(int i, int j, vector<int>* stones, vector<int>* presum, vector<vector<int>>* d){

        if (j==0){
            (*d)[i][j] = 1;
        } else if(j<0){
            return 0;
        }  
         if((*d)[i][j]>=0) return (*d)[i][j];

       
        if(i==0 && (*stones)[i]==j){
            (*d)[i][j]=1;
        }
        else if(i==0 ){
            (*d)[i][j] = 0;
        }
        if((*d)[i][j]>=0) return (*d)[i][j];

        if((*presum)[i] < j){
            (*d)[i][j] = 0;
            // return (*d)[i][j];
        }
        else if ((*presum)[i]==j){
            (*d)[i][j] = 1;
            // return (*d)[i][j];
        }   

        if((*d)[i][j]>=0) return (*d)[i][j];

        if(DFS(i-1,j-(*stones)[i],stones, presum,d )==1){
            (*d)[i][j] = 1;
            return (*d)[i][j];
        }
        if(DFS(i-1, j, stones,presum,d)==1){
            (*d)[i][j] = 1;
            return (*d)[i][j];
        }
        (*d)[i][j]=0;
        return 0;
    }


    int lastStoneWeightII(vector<int>& stones) {
        
        int len =stones.size();
        int sum =0;
        vector<int> presum;
        for(int i=0;i<stones.size();i++){
            sum+=stones[i];
            presum.push_back(sum);
        }

        sum = sum/2+1;
        vector<vector<int>> d(stones.size(), vector<int>(sum+1, -1));
        for(int i=sum;i>=0;i--){
            DFS(len-1, i, &stones, &presum, &d);
        }
        int ans =0;
        for(int i= sum;i>=0;i--){
           
                if(d[len-1][i] == 1){
                    ans = abs(presum[len-1] - i - i);
                    break;
                } 
        }
        if(presum[len-1] % 2 ==0){
            if(d[len-1][sum-1] == 1){
                return 0;
            }
        }
        return ans;


    }
};