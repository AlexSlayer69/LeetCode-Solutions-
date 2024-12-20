class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.size()==0) return {0};
        if(edges.size()==1) return {0,1};
        vector<vector<int>> adj(n);
        vector<int>degrees(n,0);
        for(auto x : edges)
        {
            int src=x[0];
            int dest=x[1];
            adj[src].push_back(dest);
            adj[dest].push_back(src);
            degrees[src]++;
            degrees[dest]++;
        }

        
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(degrees[i]==1) q.push(i);
        }

        vector<int> result;

        while(!q.empty())
        {
            result.clear();
            int size=q.size();
            for( int i=0;i<size;i++)
            {
                int curr_node=q.front();
                q.pop();
                result.push_back(curr_node);
                vector<int> neigh=adj[curr_node];

                
                for( auto x : neigh)
                {
                    degrees[x]--;

                    if(degrees[x]==1) q.push(x);
                } 
            }


        }
        return result;
        
    }
};