class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int ans[2001];
        memset(ans, 0, sizeof(ans));

        for(int i = 0; i < arr.size(); ++i) {
            ans[arr[i]+1000] += 1;
        }
        
        std::sort(ans, ans+2000);
        for(int i = 2000; i > 0; i--) {
            if (ans[i] == ans[i-1] && ans[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
