class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string longWord="";
        for(int i=0;i<d.size();i++){
            int L1=longWord.length();
            int L2=d[i].size();
            if(L1>L2||(L1==L2&&longWord<=d[i]))
                continue;
            
            int one=0,two=0;
            while(one<s.length()&&two<L2){
                if(s[one]==d[i][two])
                    two++;
                one++;   
            }
            if(two==L2)
                longWord=d[i];
              
        }
        return longWord;
      
    }
};