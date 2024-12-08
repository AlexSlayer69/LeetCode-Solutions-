class Solution {
public:
    void duplicateZeros(vector<int> &arr) {
        
        int nonZeroIndex = -1, n = arr.size();
        
        for (int i = 0; i < n; ++i) 
            if (arr[i] != 0) nonZeroIndex = i;
        
        if (nonZeroIndex == -1) return;

        vector<int> ans;

        for (int i = 0; i < n; ++i) {

            ans.push_back(arr[i]);
            if (arr[i] == 0) ans.push_back(0);

            arr[i] = ans[i];
        }
    }
};