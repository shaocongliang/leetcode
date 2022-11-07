class Solution {
 public:
  std::vector<vector<int>> subsets(vector<int> &nums) {
    ans.push_back(vector<int>());
    for (int i = 1; i <= nums.size(); ++i) {
      vector<int> tmp;
      for (int j = 0; j < nums.size() - i + 1; ++j) {
        tmp.push_back(nums[j]);
        buildSubset(i - 1, j+1, nums, tmp);
        tmp.pop_back();
      }
    }
    return ans;
  }
  void buildSubset(int remain, int startPos, vector<int> &nums,
                   vector<int> &singleAns) {
    if (remain == 0) {
      ans.push_back(singleAns);
      return;
    }
    for (; startPos < nums.size(); startPos++) {
      singleAns.push_back(nums[startPos]);
      buildSubset(remain - 1, startPos + 1, nums, singleAns);
      singleAns.pop_back();
    }
  }
private:
  vector<vector<int>> ans;
};