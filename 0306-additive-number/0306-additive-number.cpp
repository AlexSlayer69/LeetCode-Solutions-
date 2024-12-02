class Solution {
public:
bool istrue(string& num,int index,int y,long prev1,long prev2)
{
    if(index==num.size())
    {
        return true;
    }
    int maxlen=y;
    if(prev1==-1){
        if(num[index]=='0'&&maxlen>1)
        {
            maxlen=1;
        }
    for(int i=1;i<=maxlen;i++)
    {
        string s=num.substr(index,i);
        cout<<s;
        long int numy=stol(s);
        cout<<numy;
        if(istrue(num,index+i,y,numy,prev2))
        {
            return true;
        }
    }
    }
    else if(prev2==-1)
    {
        if(num[index]=='0')
        {
            maxlen=1;
        }
        for(int i=1;i<=maxlen;i++)
        {
            string s=num.substr(index,i);
            long int numy=stol(s);
            cout<<numy;
            if(istrue(num,index+i,y,prev1,numy))
            {
                return true;
            }
        }
    }
    else 
    {
        long int numy=prev1+prev2;
        cout<<numy;
        string s=to_string(numy);
        int sizeg=s.size();
        if(sizeg>num.size()-index)
        {
            cout<<"bye";
            return false;
        }
        string suby=num.substr(index,sizeg);
        long int go=stol(suby);
        if(go!=numy)
        {
            return false;
        }
        return istrue(num,index+sizeg,maxlen,prev2,go);
    }
    return false;
}
    bool isAdditiveNumber(string num) {
        if(num.size()<3)
        {
            return false;
        }
        int size=num.size();
        int maxlen=(size-1)/2;
        return istrue(num,0,maxlen,-1,-1);
    }
};