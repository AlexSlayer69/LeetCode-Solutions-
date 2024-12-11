class Solution {
public:
    int balancedStringSplit(string s) {
        int balancedString = 0;
        int count = 0;
        for(char c : s)
        {
            if(c == 'R')
                balancedString++;
            else if(c == 'L')
                balancedString--;
            if(balancedString == 0)
                count++; 
        } 
        return count;   
    }
};