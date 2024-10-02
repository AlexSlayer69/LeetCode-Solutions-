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
        
        unordered_set<string> st(wordList.begin(),wordList.end());
        unordered_map<string,bool> vis;
        st.insert(beginWord);

        if(find(wordList.begin(),wordList.end(),endWord) == wordList.end()) return 0;
        
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
                for(int i=0;i<node.size();i++){
                    char a = node[i];
                    for(char b='a';b<='z';b++)
                    {
                        node[i]=b;
                        if(st.find(node) != st.end()){
                            if(!vis[node]) q.push(node);
                        }
                    }
                    node[i]=a;
                }
            }
            level++;
        }

        return 0;
    }
};