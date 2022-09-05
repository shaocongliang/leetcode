class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    if (intervals.empty()) {
      intervals.push_back(newInterval);
      return intervals;
    }
    bool inInterval[2];
    int range[2];

    findPos(intervals, newInterval[0], inInterval[0], range[0]);
    findPos(intervals, newInterval[1], inInterval[1], range[1]);

    vector<int> vec(2, 0);
    if (!inInterval[0]) {
      vec[0] = newInterval[0];
    } else {
      vec[0] = intervals[range[0]][0];
    }

    if (!inInterval[1]) {
      vec[1] = newInterval[1];
    } else {
      vec[1] = intervals[range[1]][1];
      range[1] += 1;
    }

    intervals.erase(intervals.begin() + range[0], intervals.begin() + range[1]);
    intervals.insert(intervals.begin() + range[0], vec);
    return intervals;
  }

 private:
  void findPos(const vector<vector<int>> &intervals, int val, bool &range,
               int &intc) {
    for (int i = 0; i < intervals.size(); ++i) {
      if (val < intervals[i][0]) {
        range = false;
        intc = i;
        return;
      } else if (val <= intervals[i][1]) {
        range = true;
        intc = i;
        return;
      } else {
        range = false;
        intc = i + 1;
      }
    }
  }
};