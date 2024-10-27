class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        string str1 = "",str2 = "";
        while(n1--) str1 += s1;
        while(n2--) str2 += s2;
        int ans = 0;
        int j = 0;
        for(int i =0;i< str1.length();i++){
            if(str1[i] == str2[j]){
                if(j == str2.length()-1){
                    if((i+1)%s1.length() == 0){
                        ans++;
                        ans*=(str1.length()/(i+1));
                        i = str1.length()-(str1.length()%i); 
                        j=0;
                    }
                    else{
                        ans++;
                        j = 0;
                    }
                }
                else j++;
            }
        }
        return ans;
    }
};