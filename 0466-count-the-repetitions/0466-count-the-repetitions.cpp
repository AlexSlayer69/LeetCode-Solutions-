class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        string str1 = "",str2 = "";
        while(n1--) str1 += s1;
        while(n2--) str2 += s2;
        int l1 = str1.length(),l2 = str2.length();
        int ans = 0;
        int j = 0;
        for(int i =0;i< l1;i++){
            if(str1[i] == str2[j]){
                if(j == l2-1){
                    if((i+1)%l1 == 0){
                        ans++;
                        ans*=(l1/(i+1));
                        i = l1-(l1%i); 
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