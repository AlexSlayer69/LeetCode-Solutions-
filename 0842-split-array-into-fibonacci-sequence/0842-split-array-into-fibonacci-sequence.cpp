class Solution {
public:
    bool fun(vector<int>&ans,string num,int ind)
    {
        if(ind==num.size())
        {
            return ans.size()>2;
        }
        long long int val=0;
        for(int i=ind;i<num.size();i++)
        {
            val=val*10+(int)(num[i]-'0');
            if(val>INT_MAX)
            {
                return false;
            }
            long long int y=0;
            if(ans.size()>=2)
            {
                y=ans[ans.size()-2];
                y=y+ans[ans.size()-1];
            }
            if(ans.size()<2 || y==val)
            {
                ans.push_back(val);
                if(fun(ans,num,i+1))
                {
                    return true;
                }
                ans.pop_back();
            }
            if(i==ind and num[i]=='0')
            {
                return false;
            }
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string num)
    {
        vector<int>ans;
        fun(ans,num,0);
        return ans;
    }
};