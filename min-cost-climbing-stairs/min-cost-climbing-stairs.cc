class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() < 3)
            return *std::min_element(cost.begin(), cost.end());
        std::size_t len = cost.size();
        auto ans = new int[len];
        ans[0] = cost[0];
        ans[1] = cost[1];
        for (std::size_t i = 2; i < len-1; ++i)
            ans[i] = std::min(ans[i-2], ans[i-1]) + cost[i];
        return std::min(ans[len-3] + cost[len-1], ans[len-2]);
    }
};
