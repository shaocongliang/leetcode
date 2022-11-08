class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 2) {
            return nums.size();
        }
        std::set<int> ks;
        for(std::size_t i = 0; i < nums.size(); ++i) {
            if(ks.find(nums[i]) == ks.end()) {
               ks.insert(nums[i]);
            }
        }
        
        int max = 1;
        int cur = max;
        int prev = *ks.begin();
        for(auto it = ++ks.begin(); it != ks.end(); ++it) {
            if(*it - prev == 1) {
                cur+= 1;
            } else {
                if(cur > max) {
                    max = cur;
                }
                cur = 1;
            }
            prev = *it;
        }
        if(cur>max) {
            max = cur;
        }
        return max;
    }
};