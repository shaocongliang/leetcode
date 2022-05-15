class Solution {
public:
    map<int, int> meetingNoAndPos;
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) {
            return true;
        }
        for(int i = 0; i < intervals.size(); ++i) {
            if(meetingNoAndPos.find(intervals[i][0]) != meetingNoAndPos.end()) {
                return false;
            }
            meetingNoAndPos[intervals[i][0]] = intervals[i][1];
        }

        int end = -1;
        int nextStart = -1;
        auto endIter = --meetingNoAndPos.end();
        for(auto it = meetingNoAndPos.begin(); it != endIter;) {
            end = it->second;
            std::advance(it, 1);
            nextStart = it->first;
            if(end > nextStart) {
                return false;
            }
        }
        return true;
    }
};