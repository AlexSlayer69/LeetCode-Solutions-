class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        std::unordered_map<std::string, int> memo;
        const int n = needs.size();

        auto encode = [](const std::vector<int> &currNeeds) -> std::string {
            std::string result;
            for (int need : currNeeds) {
                result += std::to_string(need) + ",";
            }
            result.pop_back();
            return result;
        };

        auto dfs = [&](auto &&self, std::vector<int> &currNeeds) -> int {
            std::string key = encode(currNeeds);
            if (auto it = memo.find(key); it != memo.end()) {
                return it->second;
            }

            int totalPrice = 0;
            for (int i = 0; i < n; ++i) {
                totalPrice += price[i] * currNeeds[i];
            }

            for (const auto &offer : special) {
                std::vector<int> nextNeeds = currNeeds;
                bool canOffer = true;

                for (int i = 0; i < n; ++i) {
                    nextNeeds[i] -= offer[i];
                    if (nextNeeds[i] < 0) {
                        canOffer = false;
                        break;
                    }
                }

                if (canOffer) {
                    totalPrice = std::min(totalPrice, self(self, nextNeeds) + offer.back());
                }
            }

            return memo[key] = totalPrice;
        };

        return dfs(dfs, needs);
    }
};