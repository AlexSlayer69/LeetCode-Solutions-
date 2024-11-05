class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int> pse(n,0);
        vector<int> nse(n,0);
        stack<int> s;
        for(int i = n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            if(s.empty()) nse[i] = n;
            else nse[i] = s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = 0;i< n;i++){
            while(!s.empty() && arr[s.top()] > arr[i]) s.pop();
            if(s.empty()) pse[i] = -1;
            else pse[i] = s.top();
            s.push(i);
        }   
        for(auto it : pse) cout << it << " ";
        cout << endl;
        for(auto it : nse) cout << it << " ";
        long sum = 0;
        for(int i = 0;i<n;i++){
            sum = (sum + arr[i]*((long long)(i - pse[i])*(nse[i] - i) % mod)) % mod;
        }
        return sum;
    }
};