class Solution {
 public:
  int numDistinct(string s, string t) {
    int len1 = s.size();
    int len2 = t.size();
    if (len1 < len2) {
      return 0;
    }
    if (len1 == len2) {
      if (s == t) {
        return 1;
      } else {
        return 0;
      }
    }
    unsigned int ans[len1 + 1][len2 + 1];
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i <= len1; ++i) {
      ans[i][0] = 1;
    }
    
    for (int i = 1; i <= len1; ++i) {
      for (int j = 1; j <= len2; ++j) {
        if (s[i-1] == t[j-1]) {
          ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        } else {
          ans[i][j] = ans[i - 1][j];
        }
      }
    }
    return ans[len1][len2];
  }
};
