class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int tempm=minutes;
        int ans=0;
        for(int i=0;i<grumpy.size();i++){
            if(grumpy.at(i)==0){
                    ans+=customers.at(i);
                    customers.at(i)=0;
            }
        }
        int sm=0,temp=0;
        for(int j=0;j<customers.size();j++){
            while(minutes!=0){
                temp+=customers.at(j);
                j++;
                minutes--;
            }
            if(temp>sm){
                sm=temp;
            }
            if(minutes==0&&j<customers.size()){
                temp+=customers.at(j);
                temp-=customers.at(j-tempm);
            }   
        } 
        if(temp>sm){
                sm=temp;
            }
        return sm+ans;
    }
};