class Solution {
public:
    vector<int> ans;
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> valAndPos;
        for(int i = 0; i < intervals.size(); ++i) {
            valAndPos[intervals[i][0]] = i;
        }
        for(int i = 0; i < intervals.size(); ++i) {
            int sec = intervals[i][1];
            int pos = -1;
            if(sec == intervals[i][0]) {
                ans.push_back(i);
                continue;
            }
            auto iter = valAndPos.lower_bound(sec);
            if(iter == valAndPos.end()) {
                ans.push_back(pos);
            } else {
                ans.push_back(iter->second);     
            }
        }
        return ans;
    }
};