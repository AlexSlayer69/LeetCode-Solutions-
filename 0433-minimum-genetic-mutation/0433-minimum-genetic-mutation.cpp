class Solution {
public:

    bool isOnediff(string s1,string s2){
        int count = 0;
        for(int i =0;i<8;i++){
            if(s1[i] != s2[i]) count++;
        }
        return (count == 1) ? true : false;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(find(bank.begin(),bank.end(),endGene) == bank.end()) return -1;
        if(find(bank.begin(),bank.end(),startGene) == bank.end()) bank.push_back(startGene);
        unordered_map<string,vector<string>> adj;
        for(auto it : bank){
            for(auto it2: bank){
                if(isOnediff(it,it2)){
                    adj[it].push_back(it2);
                }
            }
        }
        queue<string> q;
        unordered_map<string,bool> vis;
        int ans = 1;
        q.push(startGene);
        while(!q.empty()){  
            int n = q.size();
            for(int i =0;i<n;i++){
                string s = q.front();
                q.pop();
                vis[s] = true;
                for(auto it : adj[s]){
                    if(it == endGene) return ans;
                    else if(!vis[it]){
                        q.push(it);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};