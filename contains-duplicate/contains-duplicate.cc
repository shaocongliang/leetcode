class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      set<int> s;
      for(auto &it : nums) {
        if(s.find(it) != s.end()) {
          return true;
        } else {
          s.insert(it);
        }
      }
      return false;
    }
};
