map<char, string> lt = {
    { '2' , "abc" },
    { '3' , "def" },
    { '4' , "ghi" },
    { '5' , "jkl" },
    { '6' , "mno" },
    { '7' , "pqrs" },
    { '8' , "tuv" },
    { '9' , "wxyz" }
};
  
class Solution {
public:
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        string s;
        s.resize(digits.length());
        dfs(0, digits.length(), digits, s);
        return ans;
    }
    void dfs(int index, int len, const string &digits, string &res) {
        if (index == len) {
            if(!res.empty()) {
                ans.push_back(res);
            }
            return;
        }
        string ls = lt[digits[index]];
        for(int i = 0; i < ls.size(); ++i) {
            res[index] = ls[i];
            dfs(index+1, len, digits, res);
            res[index] = 0;
        }
    }
};
