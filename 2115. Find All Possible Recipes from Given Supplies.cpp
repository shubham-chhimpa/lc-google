//https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
 
        vector<string> ans;
        
        unordered_set<string> ss;
        
        int n = recipes.size();
        for(auto supply : supplies){
            ss.insert(supply);
        }
        
        unordered_map<string,vector<string>> graph;
        unordered_map<string,int> indegree;
        
        for(auto r : recipes){
            indegree[r] = 0;
        } 
        
        for(int i=0;i<n;i++){
            for(auto ing : ingredients[i]){
                if(ss.find(ing) ==ss.end()){
                    graph[ing].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }
        
        queue<string> q;
        
        for(auto [k,v] : indegree){
            if(v==0) q.push(k);
        }
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto neigh : graph[curr]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        return ans;
        
    }
};
