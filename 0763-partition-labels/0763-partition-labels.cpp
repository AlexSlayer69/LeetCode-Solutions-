class Solution {
public:
    vector<int> partitionLabels(string s) {
       
       unordered_map<char,int>hash;
       vector<int>ans;
       set<char>st;
       
       for(auto it:s){
           hash[it]++;
       }
     
       int i=0;
       int count=0;
       
       while(i<s.length()){
        
        do{
           st.insert(s[i]);
           hash[s[i]]--;
           if(!hash[s[i]]){
               st.erase(s[i]);
           }
           i++;
           count++;
         }while(!st.empty() && i<s.length());
       
         ans.push_back(count);
         count=0;
       }
    
       return ans;
    }
};