class Solution {
 public:
  int triangleNumber(vector<int>& nums) {
    ans = 0;
    std::sort(nums.begin(), nums.end());
    int len = nums.size();
    if(len < 3) {
      return 0;
    }
    
    int max = nums[len-1];
    for(int i = 0; i < len-2; ++i) {
      for(int j = i+1; j < len-1; ++j) {
          auto iter = std::lower_bound(nums.begin()+j+1, nums.end(), nums[i]+nums[j]);
          ans += iter-(nums.begin()+j+1);  
      }
    }
    return ans;
  }
 private:
  int ans;
};
