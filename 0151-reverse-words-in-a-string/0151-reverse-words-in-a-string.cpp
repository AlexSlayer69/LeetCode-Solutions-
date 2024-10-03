class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        if(n == 0) return "";
        
        int i = 0, j = 0,l=0;
        string st = "";

        while(l < n && s[l] == ' ') l++;
        while(l<n){
            if(s[l] != ' '){
                st += s[l];
                l++;
            }
            else{
                st += ' ';
                while(l < n && s[l]  == ' ') l++;
            }    
        }
        if(st.back() == ' ') st.pop_back();
        n = st.length();

        while(i < n && j < n){
            while(j < n && st[j] != ' ') j++;
            int k = i-1;    
            while(i <= (k+j)/2){
                swap(st[i],st[j-i+k]);
                i++;
            }
            j++;
            i = j;
        }
        i = 0;
        while(i < n/2){
            swap(st[i],st[n-i-1]);
            i++;
        }
        return st;
    }
};