class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& cs, int target) {
        vector<int> solu;
        int sum = 0;
        for(int i = 0; i < cs.size(); ++i) {
            solu.push_back(cs[i]);
            dfs(cs, sum +cs[i], target, i, solu);
            solu.pop_back();
        }
        return ans;
    }
    void dfs(const vector<int>& cs, int sum, const int target, int idx, vector<int> solu) {
        if(sum == target) {
            ans.push_back(solu);
            return;
        }
        if (sum > target) {
            return;
        }
        for(;idx < cs.size(); idx++) {
            solu.push_back(cs[idx]);
            dfs(cs, sum+cs[idx], target, idx, solu);
            solu.pop_back();
        }
    }
private:
    vector<vector<int>> ans;
};