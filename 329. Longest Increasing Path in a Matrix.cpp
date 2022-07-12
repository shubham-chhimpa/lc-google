//https://leetcode.com/problems/longest-increasing-path-in-a-matrix/


class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    int mx =INT_MIN;
    
    bool isSafe(int x,int y,int rows,int cols){
        if(x<0 || x>=rows || y<0 || y>=cols) return false;
        return true;
    }
    
    int dfs(vector<vector<int>> &matrix,int x,int y, int rows,int cols,vector<vector<int>> &memo){
        
        if(memo[x][y] !=-1) return memo[x][y];
  
        int ans =1;
        for(int i=0;i<4;i++){
            int xn = dx[i]+x;
            int yn = dy[i]+y;
            if(isSafe(xn,yn,rows,cols) && matrix[x][y]<matrix[xn][yn]){
                ans = max(ans,1+dfs(matrix,xn,yn,rows,cols,memo));
            }
            mx = max(mx,ans);
        }
        
        return memo[x][y]=ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> memo(rows+1,vector<int>(cols+1,-1));
        mx = INT_MIN;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                dfs(matrix,i,j,rows,cols,memo);
            }
        }

        return mx;
    }
};
