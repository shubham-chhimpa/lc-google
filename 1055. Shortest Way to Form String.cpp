//https://leetcode.com/problems/shortest-way-to-form-string/

class Solution {
public:
    int shortestWay(string source, string target) {
       string remaining = target;
        int cnt=0;
        while(remaining.size() >0){
            int i= 0;
            int  j=0;
            string subsequence;
            while(i<source.size() && j<remaining.size()){
                if(source[i++] == remaining[j]){
                    subsequence += remaining[j++];
                }
            }
            
            if(subsequence.size()==0) return -1;
            cnt++;
            
            remaining = remaining.substr(subsequence.size());
        }
        
        return cnt;
    }
};
