class Solution {
 public:
  bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
    vector<vector<int>> ans(n+1, vector<int>());
    for(int i = 0; i < dislikes.size(); ++i) {
      ans[dislikes[i][0]].push_back(dislikes[i][1]);
    }

    queue<int> q;
    int color[n+1];
    memset(color, 0, sizeof color);
    for(int i = 1; i < ans.size(); ++i) {
      if(color[i] == 0) {
        q.push(i);
        color[i] = 1;
        for(auto k : ans[i]) {
          if(color[k]) {
            color[i] = -color[k];
            break;
          }
        }
        while (!q.empty()) {
          int val = q.front();
          q.pop();
          for (int i = 0; i < ans[val].size(); ++i) {
            int xx = ans[val][i];
            if (color[xx] == 0) {
              color[xx] = -color[val];
              q.push(xx);
            } else {
              if (color[xx] == color[val]) {
                return false;
              }
            }
          }
        }
      }
    }
    return true;
  }
};


