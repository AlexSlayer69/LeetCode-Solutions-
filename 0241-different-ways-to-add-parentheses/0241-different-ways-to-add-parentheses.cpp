class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        int n = s.size();
        if(n == 1 || n == 2) return vector<int>(1,stoi(s));
        vector<int> ans;
        for(int i =0;i<n;i++){
            if(s[i] == '-' || s[i] == '+' || s[i] == '*'){
                vector<int> left = diffWaysToCompute(s.substr(0,i));
                vector<int> right = diffWaysToCompute(s.substr(i+1,n -i -1));
                for(auto l: left){
                    for(auto r : right){
                        if(s[i] == '+') ans.push_back(l+r);
                        else if(s[i] == '*') ans.push_back(l*r);
                        else if(s[i] == '-') ans.push_back(l-r);
                    }
                }
            }
        }
        return ans;
    }
};