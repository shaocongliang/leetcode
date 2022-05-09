class Solution {
public:
    vector<string> ans;
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() <= 10){
            return ans;
        }
        std::map<string, int> m;
        set<string> se;
        for(int i = 0; i <= s.size()-10; i++) {
            string target = s.substr(i, 10);
            if(m.find(target) == m.end()) {
                m[target] = 1;
            } else {
                se.insert(target);
            }
        }
        for(auto it : se){
            ans.push_back(it);
        }
        return ans;
    }
};