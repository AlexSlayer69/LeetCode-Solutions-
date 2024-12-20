class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        
        vector<char> arr(n);
        unordered_map<char, int> mp;
        int maxi = INT_MIN;

        for (int i = n-1 ; i >= 0 ; i--) {
            maxi = max(maxi, s[i]-'0');
            arr[i] = maxi + '0';
            if (mp.find(s[i]) == mp.end()) {
                mp[s[i]] = i;
            }
        }

        for (int i = 0 ; i < n ; i++) {
            if (s[i] < arr[i]) {
                int ind = mp[arr[i]];
                swap(s[i], s[ind]);
                break;
            }
        }

        int ans = stoi(s);
        return ans;
    }
};