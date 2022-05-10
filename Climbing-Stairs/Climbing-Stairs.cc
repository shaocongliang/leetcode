class Solution {
public:
    int climbStairs(int n) {
        vector<int> res(n+1, 0);
        res[1] = 1;
        if(n >= 2) {
            res[2] = 2;
        }
        for(int i = 3; i <= n; i++) {
            for(int j = 1; j <=i; j++) {
                res[i] = res[i-1] + res[i-2];
            }
        }
        return res[n];
    }
};