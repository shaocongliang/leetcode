class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len = s.size();
        if(len == 0) {
            return true;
        }
        int index = 0;
        int len2 = t.length();
        for(int i = 0; i < len2; i++) {
           if(s[index] == t[i]) {
               index++;
               if (index == len) {
                   return true;
               }
           }   
        }
        return false;
    }
};