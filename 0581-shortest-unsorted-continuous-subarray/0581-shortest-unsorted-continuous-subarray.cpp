class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return 0;
        int one = 0;
        int two = n-1;
        for(int i =0;i<n-1;i++){
            if(nums[i] <= nums[i+1]) one++;
            else break;
        }
        if(one == n-1) return 0;
        for(int j = n-1;j > 0;j--){
            if(nums[j] >= nums[j-1]) two--;
            else break;
        }
        cout << one << " " << two << endl;
        int l = *min_element(nums.begin()+one,nums.begin()+two+1); //- nums.begin();
        int r = *max_element(nums.begin()+one,nums.begin()+two+1); //- nums.begin();
        cout << l << " " << r << endl;
        while(one != 0 && nums[one-1] > l) one--;
        while(two != n-1 && nums[two+1] < r) two++;
        return two-one+1;
    }
};