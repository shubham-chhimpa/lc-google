//https://leetcode.com/problems/moving-average-from-data-stream/

class MovingAverage {
public:
    int max_size = 0;
    int sum = 0;
    queue<int> q;
    MovingAverage(int size) {
        max_size = size;
        
    }
    
    double next(int val) {
        sum += val;
        q.push(val);
        if(q.size()<=max_size){
            return sum *1.0/q.size() * 1.0;
        }else{
            sum -= q.front();
            q.pop();
            return (sum)*1.0/q.size()*1.0;        
        }
      
    
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
