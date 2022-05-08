class Solution {
public:
    vector<vector<int>> ans;
    int findLastDupPos(const vector<int> &nums, int pos) {
        int i = pos;
        for(; i < nums.size(); ++i) {
            if(nums[i] != nums[pos-1]) {
                return i;
            }
        }
        return i;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        ans.push_back(vector<int>());
        for(int i = 0; i < nums.size(); i ++) {
            vector<int> v;
            int endPos = findLastDupPos(nums, i + 1);
            for(int j = i; j < endPos; j++){
                v.push_back(nums[j]);
            }
            dfs(endPos, nums, v);
        }
        return ans;
    }
    
    void dfs(int index, const vector<int> &nums, vector<int> &res) {
        if(index >= nums.size()) {
            ans.push_back(res);
            return;
        }
        int m = index;
     
             int endPos = findLastDupPos(nums, index + 1);
             for(int i = m; i < endPos; i++) {
                 for(int j = 0; j < endPos-i; j++) {
                     res.push_back(nums[i]);
                 }
                 dfs(endPos, nums, res);
                 for(int j = 0; j < endPos-i; ++j) {
                     res.pop_back();
                 }
             }  
             dfs(endPos, nums, res);  
    }
};