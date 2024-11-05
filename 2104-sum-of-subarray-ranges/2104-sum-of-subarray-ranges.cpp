class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n,0);
        vector<int> nse(n,0);
        vector<int> nle(n,0);
        vector<int> ple(n,0);
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
        while(!s.empty()) s.pop();
        for(int i = n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()] < arr[i]) s.pop();
            if(s.empty()) nle[i] = n;
            else nle[i] = s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = 0;i< n;i++){
            while(!s.empty() && arr[s.top()] <= arr[i]) s.pop();
            if(s.empty()) ple[i] = -1;
            else ple[i] = s.top();
            s.push(i);
        }   
        long long sum = 0;
        for(int i = 0;i<n;i++){
            long long a = (long long)(i - pse[i])*(nse[i] - i);
            long long b = (long long)(i - ple[i])*(nle[i] - i);
            sum = (sum + arr[i]*(b-a));
        }
        return sum;
    }
};