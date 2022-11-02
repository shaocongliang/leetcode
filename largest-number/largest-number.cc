#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  std::string largestNumber(std::vector<int>& nums) {
    std::string ans;
    std::string s1 = std::to_string(nums[0]);

    std::vector<string> numsStr;
    for (auto& it : nums) {
      numsStr.push_back(to_string(it));
    }
    string r1, r2;
    std::string max = s1;
    int index = 0;
    while (!numsStr.empty()) {
      auto& max = numsStr[0];
      index = 0;
      for (int i = 1; i < numsStr.size(); ++i) {
        r1 = max + numsStr[i];
        r2 = numsStr[i] + max;
        if (r2 > r1) {
          max = numsStr[i];
          index = i;
        }
      }
      std::cout << max << std::endl;
      ans.append(max);
      numsStr.erase(numsStr.begin() + index);
    }
    if (ans[0] == '0') {
      return "0";
    }
    return ans;
  }
};

int main(int argc, char** argv) {
  std::vector<int> nums{10, 2};
  Solution s;
  s.largestNumber(nums);
  return 0;
}