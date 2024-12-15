class Solution {
public:
    string solveEquation(string s) {
        int var = 0, cons = 0, i = 0, n = s.length();

        while(s[i] != '='){
            string temp = "";
            if(s[i] == '+' || s[i] == '-') temp += s[i], i++;

            while(s[i] >= '0' && s[i] <= '9') temp += s[i], i++;

            if(s[i] == 'x'){
                if(temp == "" || temp == "+" || temp == "-") temp += '1';
                i++;
                var += stoi(temp);
            }
            else if(temp.size() != 0) cons -= stoi(temp);
        }
        i++;

        while(i < n){
            string temp = "";
            if(s[i] == '+' || s[i] == '-') temp += s[i], i++;

            while(i < n &&  s[i] >= '0' && s[i] <= '9') temp += s[i], i++;

            if(s[i] == 'x'){
                if(temp == "" || temp == "+" || temp == "-") temp += '1';
                i++;
                var -= stoi(temp);
            }
            else if(temp.size() != 0) cons += stoi(temp); 
        }

        if(cons == 0){
            if(var == 0) return "Infinite solutions";
            else return "x=0";
        } 

        if(var == 0) return  "No solution";

        int hcf = __gcd(var, cons);
        var /= hcf;
        cons /= hcf;

        if(var < 0) var *= -1, cons *= -1;
        string ans = "";
        if(var != 1) ans += to_string(var);
        ans += "x=";

        ans += to_string(cons);
        return ans;
    }
};