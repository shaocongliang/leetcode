class Solution {
public:
    string reverseWords(string s) {
        std::string ans;
        int val = 0;
        std::string word;
        for (const char& ch : s) {
            if (val == 1) {
                if (ch == ' ') {
                    ans.insert(0, " " + word);
                    word.clear();
                    val = 0;
                } else {
                    word.push_back(ch);
                }
            } else {
                if (ch != ' ') {
                    word.push_back(ch);
                    val = 1;
                }
            }
        }
        if (val) {
            ans.insert(0, word);
            return ans;
        }
        if (!ans.empty()) return ans.substr(1);
        return ans;
    }
};
