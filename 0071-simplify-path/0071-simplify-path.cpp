class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string ans = "";
        int n = path.size();

        for(int i = 0;i < n;i++){
            if(path[i] == '/') continue;
            string temp;
            while(i < n && path[i] != '/'){
                temp += path[i];
                i++;
            }
            if(temp == ".") continue;
            else if(temp == ".."){
                if(!s.empty()) s.pop();
            }
            else s.push(temp);
        }
        
        while(!s.empty()){
            ans = "/" + s.top() + ans;
            s.pop();
        }
        
        if(ans.size() == 0) return "/";
        
        return ans;
    }
};