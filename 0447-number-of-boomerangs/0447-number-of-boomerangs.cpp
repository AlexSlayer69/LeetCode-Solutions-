class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        vector<int> dist;
        int i,j,n=points.size(),ans=0;
        for(i=0;i<n;i++){
            unordered_map<int,int> distcount;
            
            for(j=0;j<n;j++){
             if(i!=j){
                    int x1=points[i][0],y1=points[i][1];
                int x2=points[j][0],y2=points[j][1];
                int dis=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                distcount[dis]++;
             }
                // dist.push_back(dis);

            }

            for(auto itr: distcount){
                int x=itr.second;
                ans+=x*(x-1);
            }
        }

    
return ans;
    }
};