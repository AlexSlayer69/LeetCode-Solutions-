class Solution {
public:
    int findSpecialInteger(vector<int>& arr) 
    {
        int size=arr.size();
        int occur=size/4;
        map<int,int>mp;
        for(int i=0;i<size;i++)
            mp[arr[i]]++;
        for(auto it : mp)
        {
            if(it.second>occur)
                return it.first;
        }
        return -1;
    }
};