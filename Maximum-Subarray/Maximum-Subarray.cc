class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = -123456789;
        int temp = 0;
        int val = 0;
        for(int i = 0; i < nums.size(); ++i) {
            val = temp + nums[i];
            if(val > sum) {
                if(temp < 0) {
                    sum = nums[i];
                    temp = nums[i];
                } else {
                    sum = val;
                    temp = sum;
                }
            } else {
                if(temp < 0) {
                    if(temp > nums[i]) {
                        sum = temp;
                    } else {
                        sum = nums[i];
                    }
                }
                if(val < 0) {
                    temp = 0;
                } else {
                    temp = val;
                }
            }
        }
        return sum;
    }
};