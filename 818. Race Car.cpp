//https://leetcode.com/problems/race-car/

class Solution {
public:
    int racecar(int target) {
        queue<vector<int>> q;
        q.push({0,1,0}); // pos,speed,steps;
        
        while(!q.empty()){
            auto curr =q.front();
            q.pop();
            int pos = curr[0];
            int speed = curr[1];
            int steps = curr[2];
            
            if(pos == target) return steps;
            
            if((pos+speed <=10000 && pos+speed> 0)){
                q.push({pos+speed,speed*2,steps+1});
            }
            if (speed >0 && (pos+speed > target)){
                q.push({pos,-1,steps+1});
            }
            if(speed<0 && (pos+speed <target)){
                q.push({pos,1,steps+1});
            }
        }
        
        return -1;
    }
};
