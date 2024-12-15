class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector temp;
        set<vector> vis;
        int n = mat.size(), m = mat[0].size(), sum = 0;
        priority_queue<pair<int, vector>, vector<pair<int, vector>>,
                       greater<pair<int, vector>>>
            q;
        for (int i = 0; i < n; i++) {
            sum += mat[i][0];
            temp.push_back(0);
        }
        vis.insert(temp);
        q.push({sum, temp});
        while (k--) {
            sum = q.top().first;
            temp = q.top().second;
            q.pop();
            if (!k)
                return sum;
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i] + 1 < m) {
                    int curr = sum - mat[i][temp[i]] + mat[i][temp[i] + 1];
                    temp[i]++;
                    if (!vis.count(temp)) {
                        vis.insert(temp);
                        q.push({curr, temp});
                    }
                    temp[i]--;
                }
            }
        }
        return 0;
    }
};