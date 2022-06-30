//https://leetcode.com/problems/maximum-number-of-visible-points

class Solution {
public:
    /*
    
        - In c++ in the <Math.h> file M_PI is defined for Pi(π) value
        - 1 rad = 180°/π = 57.295779513°
    */
    double getAngleBetween(int x1,int y1,int x2,int y2){
        double angle = atan2(y1-y2,x1-x2) * (180/M_PI);
        return angle;
    }
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int overlap_cnt = 0;
        int max_cnt = 0;
        vector<double> angles;
        for(auto &point : points){
            int x = point[0];
            int y = point[1];
            
            // checking if the point is overlapping/same location as the given location
            // then adding the count separately
            if(location[0] ==x && location[1]==y){
                overlap_cnt++;
            }else{
                angles.push_back(getAngleBetween(x,y,location[0],location[1]));
            }
        }
        
        sort(angles.begin(),angles.end());
        deque<double> q;
        
        for(auto a: angles){
            q.push_back(a);
            while(a-q.front() >angle){
                q.pop_front();
            }
            int size = q.size();
            max_cnt = max(max_cnt,size);
        }
        
        for(auto a: angles){
            a+=360;
            q.push_back(a);
            while(a-q.front() >angle){
                q.pop_front();
            }
            int size = q.size();
            max_cnt = max(max_cnt,size);
        }
        
        return max_cnt+overlap_cnt;
    }
};
