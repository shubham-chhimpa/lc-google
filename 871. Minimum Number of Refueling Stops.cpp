//https://leetcode.com/problems/minimum-number-of-refueling-stops/
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        int i = 0;
        int curr_pos = startFuel;
        priority_queue<int> pq;
        int cnt = 0;
        while(curr_pos <target){
            while(i<n && stations[i][0]<=curr_pos){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()) return -1;
            curr_pos+= pq.top();
            pq.pop();
            cnt++;
        }
        
        
        return cnt;
    }
};
