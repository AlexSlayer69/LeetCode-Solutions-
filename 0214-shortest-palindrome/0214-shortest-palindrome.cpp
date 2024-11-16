class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();   
        int i = 0, j = n - 1;
    
        while (j >= 0) {
            if (s[i] == s[j]) i++;  
            j--;  
        }
        
        if (i == n) return s;
  
        string temp = s.substr(i);
        reverse(temp.begin(), temp.end());
    
        return temp + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};