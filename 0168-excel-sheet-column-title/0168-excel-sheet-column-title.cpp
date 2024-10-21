class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s = "";
        while(columnNumber > 0){
            if(columnNumber%26){
                s += columnNumber%26 + 'A' -1;
            }
            else if(columnNumber == 0) break;
            else if(columnNumber == 26) {
                s += 'Z';
                break;
            }
            else{
                s += 'Z';
                columnNumber -= 26;
            }

            columnNumber /= 26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};