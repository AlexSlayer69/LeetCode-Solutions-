class Solution {
public:

    bool isRel(string word1,string word2){
        int k = 0;
        for(int i =0;i<word1.length();i++){
            if(word1[i] != word2[i]) k++;
        }
        return (k == 1);
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> graph;
        unordered_map<string,bool> vis;

        if(find(wordList.begin(),wordList.end(),beginWord) == wordList.end())
            wordList.push_back(beginWord);
        if(find(wordList.begin(),wordList.end(),endWord) == wordList.end()) return 0;
        
        for(auto it: wordList){
            for(auto it2 : wordList){
                if(isRel(it,it2))
                    graph[it].push_back(it2);
            }
        }

        for(auto it : wordList){
            vis[it] = false;
        }
        
        queue<string> q;
        q.push(beginWord);
        int level = 1;
        while(!q.empty()){
            int n = q.size();
            for(int j = 0;j<n;j++){
                string node = q.front();
                if(node == endWord) return level;
                q.pop();
                vis[node] = true;
                for(int i = 0;i<graph[node].size();i++){
                    if(!vis[graph[node][i]]) q.push(graph[node][i]);
                }
            }
            level++;
        }

        return 0;
    }
};