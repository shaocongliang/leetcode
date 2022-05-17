class Solution {
public:
    int ans;
    int findTargetSumWays(vector<int>& nums, int target) {
        map<int, map<int, int>> m;
        map<int, int> t;
        t[nums[0]] += 1;
        t[-nums[0]] += 1;
        m[0] = t;
        for(int i = 1; i < nums.size(); ++i) {
            auto val = m[i-1];
            t.clear();
            for(auto it = val.begin(); it != val.end(); ++it) {
                t[nums[i] + it->first] += it->second;
                t[-nums[i] + it->first] += it->second;
            }
            m[i] = t;
        }
        return m[nums.size()-1][target];
    }
};