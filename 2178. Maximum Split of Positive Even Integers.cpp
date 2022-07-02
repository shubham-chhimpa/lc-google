//https://leetcode.com/problems/maximum-split-of-positive-even-integers/
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        
        vector<long long > ans;
        if(finalSum%2!=0) return ans;
        for(long long i=2;i<=finalSum;i+=2){
            if( i != finalSum-i && i<finalSum-i){ 
                finalSum = finalSum-i;
                ans.push_back(i);
            }else{
                break;
            }
        }
        
        if(finalSum !=0) ans.push_back(finalSum);
        return ans;
    }
};
