class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> ans(nums.size(), 10001);
        ans[0] = 0;
        for(int i = 1; i < nums.size(); ++i) {;
            for(int j = i-1; j >= 0; j--) {
                if(j + nums[j] >=i && ans[j] + 1 < ans[i]) {
                    ans[i] = ans[j] + 1;
                }
            }
        }
        return ans[nums.size()-1];
    }
};