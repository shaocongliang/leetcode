class Solution {
public:
    bool canJump(vector<int>& nums) {
        int nextPos = nums[0];
        int gap = nums.size() - 1;
        int pos = 1;
        for(; nextPos < gap;) {
            for(; pos < nextPos; pos++) {
                if(pos + nums[pos] > nextPos) {
                    nextPos = pos + nums[pos];
                    if(nextPos >= gap) {
                        return true;
                    }
                }
            }
            pos = nextPos;
            if ( pos < gap && nums[pos] == 0) {
                return false;
            }
            nextPos = pos + nums[pos];
        }
        return true;
    }
};