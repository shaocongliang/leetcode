class Solution {
public:
    int fib(int n) {
        int n0 = 0;
        int n1 = 1;
        if( n == 0 ) { return 0; }
        if( n == 1 ) { return 1; }
        int ans = 0;
        for(int i = 2; i <= n; ++i) {
            ans = n0 + n1;
            n0 = n1;
            n1= ans;
        }
        return ans;
    }
};