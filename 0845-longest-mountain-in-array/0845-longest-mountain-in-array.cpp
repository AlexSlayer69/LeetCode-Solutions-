class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size()<3) return 0;
        int maxlen=0,sp=0,len=arr.size(),inc=0,dec=0;
        int i=0;
        while(i<len){
            if(inc && dec)maxlen=max(i-sp+1,maxlen);
            if(i==len-1) break;
            if(arr[i]<arr[i+1]){
                if(dec)sp=i;
                inc=1;dec=0;
            }
            else if(arr[i]>arr[i+1]) dec=1;
            else{
                sp=i+1;
                inc=0;dec=0;
            }
            i++;
        }
        return maxlen;
    }
};