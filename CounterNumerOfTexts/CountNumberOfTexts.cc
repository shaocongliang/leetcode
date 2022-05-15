class Solution {
public:
    int countTexts(string pressedKeys) {
        int len = pressedKeys.length();
        vector<int> ans(len+1, 0);
        ans[0] = 1;
        ans[1] = 1;

        for(int i = 1; i < len; ++i) {
            int count = charNum(pressedKeys[i] - 48);
            int n2 = findContinuousNum(pressedKeys, i);
            int bound = min(n2, count);
            if (bound == 1) {
                ans[i+1] = (ans[i+1] + ans[i]) % (1000000000+7);
            } else {
                for(int j = i+1-bound; j < i+1; ++j) {
                   ans[i+1] = (ans[i+1] + ans[j]) % (1000000000+7);
                }
            }
        }
        return ans[len] % (1000000000+7);
    }
    int findContinuousNum(const string &s, int pos) {
        int count = 1;
        int max = charNum(s[pos]);
      
        while(pos >0 && count <= max) {
            if(s[pos-1] == s[pos]) {
                count++;
                pos--;
            } else {
                return count;
            }
        }
        return count;
    }
    int charNum(const int number) {
        return number == 7 || number == 9? 4 : 3;
    }
};