class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) {
            return false;
        }
        vector<int> ans(amount+1, 20000);
        ans[0] = 0;
        for(int i = 0; i < coins.size(); ++i) {
            if(coins[i] <= amount) {
                ans[coins[i]] = 1;
            }
        }
        for(int i = 1; i <= amount; ++i) {
            vector<int> vec(coins.size(), 0);
            for(int j = 0; j < coins.size(); ++j) {
                if(i-coins[j] >= 0) {
                   vec[j] = ans[i-coins[j]];
                } else {
                    vec[j] = 20000;
                }
            }
            auto val = *std::min_element(vec.begin(), vec.end());
            if(val == 20000) {
                ans[i] = 20000;
            } else {
                ans[i] = 1 + val;
            }
        }
        return ans[amount] == 20000? -1 : ans[amount];
    }
};