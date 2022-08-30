class Solution {
public:
    int tribonacci(int n) {
        int nums[3] = {0, 1, 1};
        if(n < 3) {
            return nums[n];
        }
        unsigned int ans = 0;
        for(int i = 3; i <= n; i++) {
            ans = nums[0] + nums[1] + nums[2];
            nums[0] = nums[1];
            nums[1] = nums[2];
            nums[2] = ans;
        }
        return ans;
    }
};
