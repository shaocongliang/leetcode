class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int size1 = s1.size();       
        int size2 = s2.size();
        if(size1 + size2 != s3.size()) return false;
        int dp[size1+1][size2+1];
        memset(dp, sizeof(dp), 0);
        dp[0][0] = true;

        for(int i = 1; i <= size2; i++) {
            dp[0][i] = dp[0][i-1] && s2[i-1] == s3[i-1];
        }

        for(int j = 1; j <= size1; j++) {
            dp[j][0] = dp[j-1][0] && s1[j-1] == s3[j-1];
        }

        for(int i = 1; i <= size1; ++i) {
            for(int j = 1; j <= size2; ++j) {
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i-1+j]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        return dp[size1][size2];
    }
};
