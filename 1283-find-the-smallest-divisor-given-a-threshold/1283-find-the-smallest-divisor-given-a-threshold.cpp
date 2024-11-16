class Solution {
public:

    int divsum(vector<int> &nums,int div){
        int sum = 0;
        for(auto it : nums){
            sum += ceil((double)it*1.0/(double)div);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if(n > threshold) return -1;
        int l = 1;
        int h = *max_element(nums.begin(),nums.end());
        int mid = (l+h)/2;
        while(l <= h){
            int mid = (l+h)/2;
            int mv = divsum(nums,mid);
            if (mv <= threshold) h = mid-1;
            else l = mid+1;
        }
        return l;
    }
};