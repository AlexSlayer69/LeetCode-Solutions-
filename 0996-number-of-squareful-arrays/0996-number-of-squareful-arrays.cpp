class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        vector<int> comb;
        int res = 0;
        vector<int> visited(nums.size(), 0);

        sort(nums.begin(), nums.end());
        solve(nums, comb, res, visited);

        return res;
    }

    void solve(vector<int> &nums, vector<int> &comb, int &res, vector<int> &visited){
        if(comb.size() == nums.size()){
            res++;
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(visited[i] || (i != 0 && nums[i] == nums[i-1] && !visited[i-1])) continue;

            if(comb.size() == 0 || isSquare(comb[comb.size()-1] + nums[i])){
                visited[i] = 1;
                comb.push_back(nums[i]);
                solve(nums, comb, res, visited);
                comb.pop_back();
                visited[i] = 0;
            }
        }
    }

    bool isSquare(int num){
        int root = sqrt(num);
        return root*root == num;
    }
};