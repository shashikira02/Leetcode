class MedianFinder {
public:
    priority_queue<int>maxi;
    priority_queue<int,vector<int>,greater<int>>mini;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxi.empty() || maxi.top() > num){
            maxi.push(num);
        }
        else {
            mini.push(num);
        }
        //if size is not same or too big
        if(maxi.size() > mini.size()+1){
            int val ;
            val = maxi.top();
            maxi.pop();
            mini.push(val);
        } 
        if(mini.size()> maxi.size()+1){
            int val ;
            val = mini.top();
            mini.pop();
            maxi.push(val);
        }
    }
    
    double findMedian() {
        if(maxi.size() > mini.size()){
            return maxi.top();
        }
        if(mini.size() > maxi.size()){
            return mini.top();
        }

        return (mini.top()+maxi.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */