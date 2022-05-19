class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<int> vec(2, 0);
        if(intervals.size() == 1) {
            vec = intervals[0];
            ans.push_back(vec);
            return ans;
        }
        multimap<int, vector<int>> m;
        for(auto &it : intervals) {
            m.insert(std::make_pair(it[0], it));
        }
        
        auto it = m.begin();
        int a1 = it->second[0];
        int a2 = it->second[1];
        
        vec[0] = a1;
        vec[1] = a2;
        int b1, b2;
        ans.push_back(vec);
        for(++it; it != m.end(); ++it) {
            b1 = it->second[0];
            b2 = it->second[1];
            if (a1 < b1) {
                swap(a1, b1);
            }
            if (a2 < b2) {
                swap(a2, b2);
            }

            
            if(a1 <= b2) {
                   ans[ans.size()-1][0] = b1;
                   ans[ans.size()-1][1] = a2;
                   a1 = b1;
            } else {
                vec[0] = it->second[0];
                vec[1] = it->second[1];
                ans.push_back(vec);
            }
        }
        
        return ans;
    }
};
