class Solution {
public:
    string convert_email(string s) {
        string res = "";
        res += tolower(s[0]);

        bool found = false;
        for(int i=1; i<s.length(); i++) {
            if(s[i] == '@') {
                res += "*****";
                res.push_back(tolower(s[i-1]));
                res.push_back('@');
                found = true;
                continue;
            }

            if(found) {
                res.push_back(tolower(s[i]));
            }
        }
        return res;
    }
    string convert_phone(string s) {
        string digits = "";

        for(int i=0; i<s.length(); i++) {
            if(s[i] == '+' || s[i] == '-' || s[i] == '(' || s[i] == ')' || s[i] == ' ') {
                continue;
            }
            digits.push_back(s[i]);
        }
        int n = digits.length();
        int country_code_len = n - 10;
        if(country_code_len == 0) {
            return "***-***-" + digits.substr(n-4, 4);
        }
        if(country_code_len == 1) {
            return "+*-***-***-" + digits.substr(n-4, 4);
        }
        if(country_code_len == 2) {
            return "+**-***-***-" + digits.substr(n-4, 4);
        }
        if(country_code_len == 3) {
            return "+***-***-***-" + digits.substr(n-4, 4);
        }
        return digits;
    }
    string maskPII(string s) {
        bool is_email = false;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '@') {
                is_email = true;
                break;
            }
        }
        return is_email ? convert_email(s) : convert_phone(s);
    }
};