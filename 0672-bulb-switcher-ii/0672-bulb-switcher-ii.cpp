class Solution {
public:
    int flipLights(int n, int p) {
        if(n==1){
            if(p==0)
            return 1;
            else return 2;
        }

        else if( n==2){
            if(p==0)
            return 1;
            if(p==1)
            return 3;
            else
            return 4;
        }
        else{
            if(p==0)
            return 1;
            if(p==1)
            return 4;
            if(p==2)
            return 7;
            else
            return 8;
        }
    }
};