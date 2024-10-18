class Solution {
public:
    bool isNumber(string s) {
        bool dot_allowed = true; 
        bool sign_allowed = true;
        bool in_expo = false;
        bool num = false;
        for(int i =0;i< s.length();i++){
            if(s[i] >= '0' && s[i] <= '9'){
                sign_allowed = false;
                num = true;
            }
            else if(s[i] == '.'){ 
                sign_allowed = false;
                if(dot_allowed) dot_allowed = false;
                else return false;
            }
            else if(s[i] == '-' || s[i] == '+'){
                if(sign_allowed) sign_allowed = false;
                else return false;
            }
            else if(s[i] == 'e' || s[i] == 'E') {
                if(!num) return false;
                if(in_expo) return false;
                else{
                    dot_allowed = false;
                    sign_allowed = true;
                    num = false;
                }
                in_expo = true;
            }
            else return false;
        }
        if(!dot_allowed && !num) return false;
        if(!sign_allowed && !num) return false;
        return true;
    }
};