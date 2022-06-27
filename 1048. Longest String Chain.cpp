//https://leetcode.com/problems/longest-string-chain/
class Solution {
public:
    static bool compare(string &a,string &b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),compare);
        cout<<words[0]<<"\n";
        unordered_map<string,int> dp;
        int mx = INT_MIN;
        for(auto &word : words){
            int n = word.size();
            for(int i=0;i<n;i++){
                string pre = word.substr(0,i)+word.substr(i+1);
                dp[word] = max(dp[word],dp.find(pre)==dp.end()?1:dp[pre]+1);
                mx = max(mx,dp[word]);
            }
        }
        return mx;
    }
};
