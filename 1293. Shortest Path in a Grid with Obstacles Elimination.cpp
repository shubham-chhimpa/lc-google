//https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    bool isSafe(int x,int y,int rows,int cols){
        if(x<0 || x>= rows ||y<0 || y>= cols) return false;
        return true;
    }
    string get_state_hash(int xn,int yn,int obs){
        return to_string(xn)+","+to_string(yn)+","+to_string(obs);
    }
    unordered_set<string> vis;
    int shortestPath(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols  = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        // vector<vector<vector<int>>> vis(rows+1,vector<vector<int>>(cols+1,vector<int>(k+1,-1)));
        int mn = INT_MAX;
        q.push({{0,0},k});
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr = q.front();
                q.pop();
                int x = curr.first.first;
                int y = curr.first.second;
                int obs = curr.second;
              
                if(x==rows-1 && y==cols-1){
                    return steps;
                }
                for(int i=0;i<4;i++){
                    int xn = x+dx[i];
                    int yn = y+dy[i];
                    string state = get_state_hash(xn,yn,obs);
                    if(isSafe(xn,yn,rows,cols) && vis.find(state) ==vis.end()){
                        vis.insert(state);
                        if( grid[xn][yn]==1 && obs>0){
                            q.push({{xn,yn},obs-1});
                        }else if(grid[xn][yn]==0){
                            q.push({{xn,yn},obs});
                        }
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};
