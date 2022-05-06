class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> vec(nums.size()+1, -1);
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > nums.size() || nums[i] < 0) {
                continue;
            } else {
                vec[nums[i]] = 1;
            }
        }
        int pos = 1;
        for(; pos < vec.size(); ++pos) {
             if(vec[pos] == -1) {
                 break;
             }
        }
        return pos;
    }
};