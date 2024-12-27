class Solution {
public:
    int nearestValidPoint(int x1, int y1, vector<vector<int>>& arr) {
        
        int ans_dis=INT_MAX;
        int ans_idx=-1;

        for(int i=0;i<arr.size();i++)
        {
            int x2=arr[i][0];
            int y2=arr[i][1];

            if(x1==x2 or y1==y2)
            {	
                int dis = abs(x1 - x2) + abs(y1 - y2);

                if(dis < ans_dis)
                {
                   ans_dis = dis;
                   ans_idx=i;	
                }	
            }
            else
            continue;
        }
        return ans_idx;
    }
};