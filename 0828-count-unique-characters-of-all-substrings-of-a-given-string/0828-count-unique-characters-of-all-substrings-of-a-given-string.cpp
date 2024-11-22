class Solution {
public:
    int uniqueLetterString(string s) {
        int n=s.size();
        s="."+s;
        vector<int> last1(26, 0), last2(26, 0);
        int sum=0, temp=0;
        for(int i=1;i<=n;i++){
            int idx1=last1[s[i]-'A'];
            int idx2=last2[s[i]-'A']; 
            temp+=(i-idx1)-(idx1-idx2);
            last2[s[i]-'A']=last1[s[i]-'A'];
            last1[s[i]-'A']=i;
            sum+=temp;
        }
        return sum;
    }
};