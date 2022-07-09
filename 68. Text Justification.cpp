//https://leetcode.com/problems/text-justification/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i=0;
        int n = words.size();
        vector<string> res;
        while(i<n){
            int j = i+1;
            int can = 0;
            int wc = words[i].size();
            while(j<n && wc+words[j].size()+can+1<=maxWidth){
                wc+= words[j].size();
                can++;
                j++;
            }
            
            int vac = maxWidth -wc;
            int atleast = can ==0 ? 0:vac/can;
            int extra = can ==0 ? 0:vac % can;
            if(j==words.size()){
                atleast = 1;
                extra = 0;
            }
            string tmp;
            
            for(int k=i;k<j;k++){
                tmp += words[k];
                if(k==j-1)break;
                for(int a=0;a<atleast;a++){
                    tmp+= " ";
                }
                if(extra >0){
                    tmp+= " ";
                    extra--;
                }
            }
            
            while(tmp.size() < maxWidth){
                tmp+=" ";
            }
            res.push_back(tmp);
            i=j;
        }
        
        return res;
    }
};
