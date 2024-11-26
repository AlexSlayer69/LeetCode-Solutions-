class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int>ans(temp.size());
        stack<int>st;
        int n=temp.size();
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push(i);
                ans[i]=0;
            }
            else{
                while(st.empty()!=1 && temp[i]>=temp[st.top()]){
                    st.pop();
                }
                if(st.empty()){
                    st.push(i);
                    ans[i]=0;
                }
                else{
                    ans[i]=st.top()-i;
                    st.push(i);
                }
            }
        }
        return ans;
    }
};