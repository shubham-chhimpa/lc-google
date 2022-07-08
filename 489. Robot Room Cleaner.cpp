

//https://leetcode.com/problems/robot-room-cleaner/

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    // directions
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    void dfs(Robot& robot,int x,int y,int faceDir,unordered_set<string> &visited){
        visited.insert(to_string(x)+","+to_string(y));
        robot.clean();
        for(int i=0;i<4;i++){
            int nextFaceDir = (faceDir+i)%4;
            int xn = dx[nextFaceDir]+x;
            int yn = dy[nextFaceDir]+y;
            string hash = to_string(xn)+ "," + to_string(yn);
            if(visited.find(hash) == visited.end() && robot.move()){
                dfs(robot,xn,yn,nextFaceDir,visited);
                
                //backtracking - moving the robot to one step back
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            
            // the current direction is explored 
            //and now we are checking the next direction
            robot.turnRight();
        }
    }
    void cleanRoom(Robot& robot) {
        
        unordered_set<string> visited;
        dfs(robot,0,0,0,visited);
    }
};
