class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (!n) return 1;
        int ans = 10;
        int f = 9;
        // f(j) = f(j-1)*)(10-j+1);
        for (int j = 2; j <= n; j++) {
            f = f * (10-j+1);
            ans += f;
        }
        return ans;
    }
};
