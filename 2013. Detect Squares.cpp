//https://leetcode.com/problems/detect-squares/

class DetectSquares {
public:
    
    vector<unordered_map<int,int>> x_axis;
    
    DetectSquares() {
        x_axis = vector<unordered_map<int,int>>(1005);
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        
        x_axis[x][y]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int res = 0;
        
        for(auto &candidate : x_axis[x]){
            int yn = candidate.first;
            if(y==yn) continue;
            int side_len = abs(y-yn);
            
            // check p2 and p3 and p4 on right side
            if(x+side_len <=1000){
                int xn = x+side_len;
                res += x_axis[x][yn] * x_axis[xn][yn] * x_axis[xn][y];
                
            }
            
            //check p2 and p3 and p4 on the left side
            if(x-side_len >=0){
                int xn = x-side_len;
                res += x_axis[x][yn] * x_axis[xn][yn] * x_axis[xn][y];
            }
        }
        
        return res;
        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
