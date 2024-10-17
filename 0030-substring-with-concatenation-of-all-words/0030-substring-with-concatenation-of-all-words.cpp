class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int m=s.size(),n=words.size(),len=words[0].size();
        vector<int> ans;
        unordered_map<string,int> dic;

        for(string word: words) dic[word]++;

        for(int i=0;i<len;i++){
            unordered_map<string,int> temp;
            int lb=i,ub=i+len;
            bool flag=true;
            int count=0;
            while(ub<=m){
                if(flag){
                    temp[s.substr(ub-len,len)]++;
                    count++;
                }
                else{
                    temp[s.substr(lb-len,len)]--;
                    count--;
                }
                //cout<<"["<<lb<<","<<ub<<"]"<<","<<count<<endl;
                string subStr=s.substr(ub-len,len);
                if(temp[subStr]>dic[subStr]){
                    lb+=len;
                    flag=false;
                }
                else{
                    ub+=len;
                    flag=true;
                    if(count==n){
                       ans.push_back(lb);
                    }
                }
            }
        }
        return ans;
    }
};