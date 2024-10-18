class Solution {
public:
    string countAndSay(int n) {
        string ans = "";
        if(n == 1) return "1";
        else{
            string k = countAndSay(n-1);
            char c = 0;
            int count = 0;
            for(int i = 0;i < k.length();i++){
                if(k[i] == c) count++;
                else if(k[i] != c){
                    if(count != 0){
                        ans += (count + '0');
                        ans += c;
                    }
                    c = k[i];
                    count = 1;
                } 
                if(i == k.length()-1){
                    ans += (count + '0');
                    ans += c;
                }
            }
        }
        return ans;
    }
};