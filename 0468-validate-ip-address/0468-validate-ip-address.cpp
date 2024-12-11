class Solution {
public:
    bool validIPv4(string s) {

        int n = s.size();

        if (n == 0 || n > 3)
            return false;

        if (n == 1) {
            int val = s[0] - '0';
            if (val >= 0 && val <= 9) {
                return true;
            } else {
                return false;
            }
        }

        bool preDigi = false;
        int num = 0;

        for (int i = 0; i < n; i++) {

            if (!preDigi) {
                if (s[i] == '0' || (s[i] >= 'a' && s[i] <= 'z') ||
                    (s[i] >= 'A' && s[i] <= 'Z')) {
                    return false;
                } else {
                    int val = s[i] - '0';
                    if (val < 1 && val > 9) {
                        return false;
                    }
                    num = num * 10 + val;
                }
                preDigi = true;
            } else {
                if ((s[i] >= 'a' && s[i] <= 'z') ||
                    (s[i] >= 'A' && s[i] <= 'Z')) {
                    return false;
                }
                int val = s[i] - '0';
                if (val < 1 && val > 9) {
                    return false;
                }
                num = num * 10 + val;
            }
        }

        if (num < 1 || num > 255) {
            return false;
        } else {
            return true;
        }
    }

    bool validIPv6(string s) {

        int n = s.size();

        if (n == 0 || n > 4)
            return false;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'b' || s[i] == 'c' || s[i] == 'd' ||
                s[i] == 'e' || s[i] == 'f') {
                continue;
            } else if (s[i] == 'A' || s[i] == 'B' || s[i] == 'C' ||
                       s[i] == 'D' || s[i] == 'E' || s[i] == 'F') {
                continue;
            } else {
                int val = s[i] - '0';
                if (val >= 0 && val <= 9) {
                    continue;
                } else {
                    return false;
                }
            }
        }

        return true;
    }

    string validIPAddress(string queryIP) {

        int n = queryIP.size();

        int dots = 0;
        int semiColon = 0;

        for (int i = 0; i < n; i++) {
            if (queryIP[i] == '.') {
                dots++;
            } else if (queryIP[i] == ':') {
                semiColon++;
            }
        }

        if (dots == 3 && semiColon == 0) {

            string temp = "";

            for (int i = 0; i < n; i++) {
                if (queryIP[i] == '.') {
                    if (!validIPv4(temp)) {
                        return "Neither";
                    }
                    temp = "";
                } else {
                    temp += queryIP[i];
                }
            }

            if (!validIPv4(temp)) {
                return "Neither";
            }

            return "IPv4";

        } else if (dots == 0 && semiColon == 7) {

            string temp = "";

            for (int i = 0; i < n; i++) {
                if (queryIP[i] == ':') {
                    if (!validIPv6(temp)) {
                        return "Neither";
                    }
                    temp = "";
                } else {
                    temp += queryIP[i];
                }
            }

            if (!validIPv6(temp)) {
                return "Neither";
            }

            return "IPv6";

        } else {
            return "Neither";
        }
    }
};