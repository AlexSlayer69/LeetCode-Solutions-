class Solution {
public:
    int lengthLongestPath(string input) {
        int depth = 0;
    
        vector<int> paths; 
        int nameLen = 0;
        bool isFile = false;
        bool isStarting = true;
        int tabs = 0;
        int longest = 0;
        for (char c : input) {
            if (c == '\t') {
                
                ++tabs;
            } else if (c == '\n') {
                if (isFile) {
                    isFile = false;
                } else { 
                    int len = nameLen;
                    if (!paths.empty()) {
                        
                        len += 1 + paths.back();
                    }
                    paths.push_back(len);
                }
                isStarting = true;
                tabs = 0;
                nameLen = 0;
            } else {
                if (isStarting) {
                    isStarting = false;
                    
                    while (paths.size() > tabs) {
                        paths.pop_back();
                    }
                    tabs = 0;
                }
                
                ++nameLen;
                if (c == '.') {
                    isFile = true;
                }
                if (isFile) {
                    int curLen = nameLen;
                    if (!paths.empty()) {
                      
                        curLen += 1 + paths.back();
                    }
                    longest = max(longest, curLen);
                }
            }
        }
        return longest;
    }

    static int getBackOrZero(const vector<int>& paths) {
        if (paths.empty()) {
            return 0;
        }
        return paths.back();
    }
};