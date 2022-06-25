//https://leetcode.com/problems/minimum-time-difference/

/*
1. translate all the times into minutes value, i.e. 12:01 = 12 * 60 + 1
2. sort the value vector
3. push_back the min time + 24 * 60 to deal with min and max diff.
4. compare map[i] and map[i+1]

*/

class Solution {
public:
    void splitTime(string timePoint,vector<int> &times){
        int h = std::stoi(timePoint.substr(0,2));
        int m =  std::stoi(timePoint.substr(3,5));
        
        times.push_back(h*60+m);
        
    }
    
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        for(auto t : timePoints){
            splitTime(t,times);
        }
        
        sort(times.begin(),times.end());
        times.push_back(times[0]+24*60);
        int n = times.size();
        int mn = INT_MAX;
        for(int i=1;i<n;i++){
            int diff = times[i]-times[i-1];
           mn = min(mn,diff);
        }
        
        return mn;
    }
};
