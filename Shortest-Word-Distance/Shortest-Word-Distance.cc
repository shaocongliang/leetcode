class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int n1 = 400000;
        int n2 = 200000;
        int ans = 2000000;
        int temp = 0;
        for(int i = 0; i < wordsDict.size(); ++i) {
            if( wordsDict[i] == word1 ) {
                n1 = i;
            }
            if( wordsDict[i] == word2) {
                n2 = i;
            }
            temp = abs(n1-n2);
            if(temp < ans) {
                ans = temp;
            }
        }
        return  ans;
    }
};