class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ip;
        vector<string> temp;
        helper(temp, ip, s, 0);
        return ip;
    }

    void helper(vector<string>& temp, vector<string>& ip, string& s,int index) {
        if (index == s.size() && temp.size() == 4) {
            string validip = temp[0] + "." + temp[1] + "." + temp[2] + "." + temp[3];
            ip.push_back(validip);
            return;
        }
        string str = "";
        for (int i = index; i < s.size() && temp.size() < 4; i++) {
            if (s[i] - '0' > 9) continue;

            str = str + s[i];
            int a = stoi(str);
            if (0 <= a && a <= 255) {
                temp.push_back(str);
                helper(temp, ip, s, i + 1);
                temp.pop_back();
            }
            if (a <= 0 || a >= 255) {
                break;
            }
        }
    }
};