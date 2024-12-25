class Solution {
public:
    int binaryGap(int n) {
        int ans=0,count=0;
        string binary="";

        while(n!=1){
            if(n%2==0)
                binary='0'+binary;
            else
                binary='1'+binary;

            n/=2;
        }
        binary='1'+binary;

        for(int i=1;i<binary.length();i++){
            if(binary[i]=='0')
                count++;
            else{
                count++;
                if(count>ans)
                    ans=count;
                count=0;
            }
        }

        return ans;
    }
};