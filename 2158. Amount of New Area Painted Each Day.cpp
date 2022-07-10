//https://leetcode.com/problems/amount-of-new-area-painted-each-day/

class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        int min_start = INT_MAX;
        int max_end = INT_MIN;
        
        
        for (auto &row : paint) {
            int start = row[0];
            int end = row[1];
            min_start = min(min_start, start);
            max_end = max(max_end, end);
        }
        
        set<int> painting;
        for (int i = min_start; i < max_end; i++){
            painting.insert(i);
        }
 
        vector<int> res;
        
        for (auto &row : paint) {
            int count = 0;
            int start = row[0];
            int end = row[1];
            auto it = painting.lower_bound(start);
            while (it != painting.end() && *it < end) {
                it = painting.erase(it);
                count++;
            }
            
            res.push_back(count);
        }
        
        return res;        
    }
};
