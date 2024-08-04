class Solution {
public:
    int mySqrt(int x) {
        int b = 0;
        int e = x;
        long root = x/2;
        for (;;) {
            if (root*root <= x && (root+1)*(root+1) > x)
                return root;
            if (root * root > x) {
                e = root;
                root = (b + e) / 2;
            } else {
                b = root + 1;
                root = (b + e)/2;
            }
        }
    }
};
