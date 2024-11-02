class Solution {
public:
    int findComplement(int num) {
        vector<int> bin;
        while(num){
            bin.push_back(num%2);
            num /= 2; 
        }
        int ans = 0;
        for(int i = bin.size()-1;i>=0;i--){
            ans *= 2;
            if(!bin[i]) ans++;
        }
        return ans;
    }
};