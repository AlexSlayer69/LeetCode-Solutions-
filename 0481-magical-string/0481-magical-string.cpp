class Solution {
public:
    int magicalString(int n) {
        string MagicString = "122";
        int index = 2;
        while(MagicString.size() < n){
            int repeat = MagicString[index] - '0';
            char nextChar = MagicString.back() ^ 3;
            MagicString += string(repeat, nextChar);
            index++;
        }

        return count(MagicString.begin(),MagicString.begin() + n, '1');
    }
};