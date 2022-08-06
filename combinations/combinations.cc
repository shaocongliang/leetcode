class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
      vector<int> nums;
      for(int i = 1; i <= n; ++i) {
        nums.push_back(i);
      }
      
      vector<int> exam;
      combin(k, 0, 0, n, nums, exam);
      return ans;
    }
    void combin(int k, int cur, int pos, int end, const vector<int> &nums, vector<int> &exam) {
      if(cur == k) {
        ans.push_back(exam);
        return;
      }
      for(;pos < end; ++pos) {
        exam.push_back(nums[pos]);
        combin(k, cur+1, pos+1, end, nums, exam);
        exam.pop_back();
      }
    }
  vector<vector<int>> ans;
};
