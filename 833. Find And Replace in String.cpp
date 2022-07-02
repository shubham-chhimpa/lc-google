
//https://leetcode.com/problems/find-and-replace-in-string

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        
        vector<pair<int,int>> rSorted;
        int n = indices.size();
        for(int i=0;i<n;i++){
            rSorted.push_back({indices[i],i});
        }
        
        sort(rSorted.begin(),rSorted.end(),greater<pair<int,int>>());
        
        for(auto p : rSorted){

            int index = p.first;
            int i = p.second;
            string source = sources[i];
            string target = targets[i];
            if(s.substr(index,source.size()) == source){
                s = s.substr(0,index) + target + s.substr(index + source.size());
            }
        }
        
        return s;
        
    }
};
