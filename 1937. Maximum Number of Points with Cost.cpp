//https://leetcode.com/problems/maximum-number-of-points-with-cost/

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size();
        int cols = points[0].size();
        vector<long long> dp(points[0].begin(),points[0].end());
        vector<long long> right(cols,0);
        vector<long long> left(cols,0);
        for(int r=1;r<rows;r++){
            
            for(int c=0;c<cols;c++){
                if(c==0){
                    left[c] = dp[c];
                }else{
                    left[c] = max(left[c-1]-1,dp[c]);
                }
            }
            
            for(int c=cols-1;c>=0;c--){
                if(c==cols-1){
                    right[c]= dp[c];
                }else{
                    right[c] = max(right[c+1]-1,dp[c]);
                }
            }
            
            for(int c=0;c<cols;c++){
                dp[c] = points[r][c] + max(left[c],right[c]);
            }
        }
        
        long long mx = 0;
        for(int i=0;i<cols;i++){
            mx = max(mx,dp[i]);
        }
        return mx;
    }
};
