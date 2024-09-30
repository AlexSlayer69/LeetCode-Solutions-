class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min = strs[0].length(),n = strs.size();
        for(int i = 0;i<n;i++){
            if(min > strs[i].length())
                min = strs[i].length();
        }
        if(min == 0) return "";
        int i = 0;
        string s ="";
        while(i < min){
            char common = strs[0][i];
            for(int j = 0;j<n;j++){
                if(strs[j][i] != common)
                    return s;    
            }
            s += common;
            i++;
        }
        return s;
    }
};