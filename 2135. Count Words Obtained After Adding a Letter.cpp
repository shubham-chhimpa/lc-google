//https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/


class Solution {
public:
    
    int getHash(string &word,int k=0,bool skip=false){
        int n  = word.size();
        int hash = 0;
        for(int i=0;i<n;i++){
            if(skip && i==k) continue;
            hash += (1<< (word[i]-'a'));
        }
        
        return hash;
    }
    
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> hashs;
        for(string &startWord : startWords){
            hashs.insert(getHash(startWord));
        }
        int cnt = 0;
        for(string &targetWord : targetWords){
            
            for(int k=0;k<targetWord.size();k++){
                
                if(hashs.find(getHash(targetWord,k,true)) != hashs.end()){
                    cnt++;
                    break;
                }    
            }
            
        }
        
        return cnt;
    }
};
