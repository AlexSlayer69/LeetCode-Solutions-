class Solution {
public:
    string getHint(string secret, string guess) {
        int cow  = 0;
        int bull = 0;
        vector<bool>counted(secret.length(),false);
      for(int i=0;i<secret.length();i++){
        if(guess[i]==secret[i]){
            bull++;
        }else{
        for(int y=0;y<secret.length();y++){
            if(guess[i]==secret[y] && guess[y]!=secret[y] && !counted[y]){
                cow++;
                counted[y] = true;
                break;
            }
        }
        }
      }
      string ans = "";
      ans+=to_string(bull);
      ans+='A';
      ans+=to_string(cow);
      ans+='B';
      return ans;
    }
};