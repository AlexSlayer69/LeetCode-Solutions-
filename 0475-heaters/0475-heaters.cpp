class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters)
    {
        // Sort the input data
        std::sort(houses.begin(), houses.end());
        std::sort(heaters.begin(), heaters.end());

        // Find the max radius
        int mid = INT_MAX;
        int i {0}, j {0}, sol {0};
        while (i < houses.size())
        {
            // Calculate the midpoint
            mid = (j + 1 < heaters.size()) ? ( (heaters[j] + heaters[j + 1]) / 2 ) : INT_MAX;
            if (houses[i] <= mid)
            {
                sol = std::max(sol, std::abs(houses[i] - heaters[j]));
                i++;
            }
            else
            {
                j++;
            }
        }
        return sol;
    }
};