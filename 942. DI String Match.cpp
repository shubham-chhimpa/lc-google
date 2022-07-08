//https://leetcode.com/problems/di-string-match/

class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ans;
        int start = 0;
        int end = s.size();
        for(int i=0;i<=s.size();i++){
            if(i==s.size() ||s[i] == 'I'){
                ans.push_back(start++);
            }else{
                ans.push_back(end--);
            }
        }

            
        return ans;
    }
};
