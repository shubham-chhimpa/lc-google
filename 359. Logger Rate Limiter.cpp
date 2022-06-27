//https://leetcode.com/problems/logger-rate-limiter/

class Logger {
public:
    unordered_map<string,int> cache;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(cache.find(message)!=cache.end() and cache[message]+10>timestamp){
            
            return false;
        }
        cache[message]=timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
