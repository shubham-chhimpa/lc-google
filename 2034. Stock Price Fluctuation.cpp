//https://leetcode.com/problems/stock-price-fluctuation/

class StockPrice {
public:
    
    int currentTime = 0;
    unordered_map<int,int> priceMap;
    priority_queue<pair<int,int>,vector<pair<int,int>>> maxPQ;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minPQ;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        currentTime = max(timestamp,currentTime);
        priceMap[timestamp] = price;
        minPQ.push({price,timestamp});
        maxPQ.push({price,timestamp});

    }
    
    int current() {
        return priceMap[currentTime];
    }
    
    int maximum() {
        auto current = maxPQ.top();
        
        while(current.first != priceMap[current.second]){
            maxPQ.pop();
            current = maxPQ.top();
        }
        
        return current.first;
    }
    
    int minimum() {
        auto current = minPQ.top();
        
        while(current.first != priceMap[current.second]){
            minPQ.pop();
            current = minPQ.top();
        }
        
        return current.first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
