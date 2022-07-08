//https://leetcode.com/problems/time-needed-to-inform-all-employees/

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res = 0;
        for(int i=0;i<n;i++){
            res = max(res,dfs(i,manager,informTime));
        }
        return res;
    }
    
    int dfs(int source,vector<int> &manager,vector<int> &informTime){
        if(manager[source] != -1){
            informTime[source] += dfs(manager[source],manager,informTime);
            manager[source]= -1;
        }
        
        return informTime[source];
    }
};
