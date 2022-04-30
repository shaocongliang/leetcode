class Solution {
public:
    bool isAllVisited(const vector<bool> vis) {
        return vis.end() == std::find(vis.begin(), vis.end(), false);
    }

    void getMutation(vector<bool> visited, const vector<int> &nums, vector<int> ans, int index) {
        if(isAllVisited(visited)) {
            res.push_back(ans);
            return;
        }

        for(int i = 0; i < nums.size(); ++i) {
            if(!visited[i]) {
                ans[index++] = nums[i];
                visited[i] = true;
                getMutation(visited, nums, ans, index);
                visited[i] = false;
                index--;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<int> ans(nums.size(), 0);
        getMutation(visited, nums, ans, 0);
        return res;
    }

private:
    vector<vector<int>> res;
};