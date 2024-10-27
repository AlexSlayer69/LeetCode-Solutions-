class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = s1.size(), len2 = s2.size();

        vector<int> repeatCount(len2 + 1, 0);
        vector<int> nextIndex(len2 + 1, 0);
        
        int cnt = 0;
        int ptr2 = 0;
        
        for(int i = 1;i <= n1;i++){
            for(int j = 0;j< len1;j++){
                if(s1[j] == s2[ptr2]){
                    if(ptr2 == len2-1){
                        cnt++;
                        ptr2=0;
                    }
                    else ptr2++;
                }
            }

            repeatCount[i] = cnt;
            nextIndex[i] = ptr2;

            for (int start = 0; start < i; start++){
                if (nextIndex[start] == ptr2) {
                    int prefixCount = repeatCount[start];
                    int patternCount = (repeatCount[i] - repeatCount[start]) * 
                                       ((n1 - start) / (i - start));
                    int suffixCount = repeatCount[start + (n1 - start)%(i - start)]
                                      -repeatCount[start];
                    
                    return (prefixCount + patternCount + suffixCount) / n2;
                }
            }
        }
        return repeatCount[n1]/n2;
    }
};