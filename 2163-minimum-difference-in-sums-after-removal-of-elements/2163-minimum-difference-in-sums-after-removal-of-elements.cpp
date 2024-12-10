long long small[100002], large[100002];

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        long long lsum = accumulate(begin(nums), begin(nums)+n, 0LL);
        long long rsum = accumulate(begin(nums)+n*2, end(nums), 0LL);
        priority_queue<int> maxheap(begin(nums), begin(nums)+n);
        priority_queue<int, vector<int>, greater<int>> minheap(begin(nums)+n*2, end(nums));
        
       
        small[0] = lsum, large[n] = rsum;
 
        for (int i = 0; i < n; ++i) {
            if (nums[n+i] < maxheap.top()) {
                lsum += nums[n+i] - maxheap.top();
                maxheap.pop();
                maxheap.push(nums[n+i]);
            }
            if (nums[2*n-1-i] > minheap.top()) {
                rsum += nums[2*n-1-i] - minheap.top();
                minheap.pop();
                minheap.push(nums[2*n-1-i]);
            }
            small[i+1] = lsum, large[n-1-i] = rsum;
        }

        long long res = LLONG_MAX;
        for (int i = 0; i <= n; ++i) {
            res = min(res, small[i] - large[i]);
        }
        return res;
        
    }
};