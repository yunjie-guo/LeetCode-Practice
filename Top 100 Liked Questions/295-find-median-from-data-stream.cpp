class MedianFinder {
public:
    std::priority_queue<int,vector<int>> min_half;
    std::priority_queue<int,vector<int>,greater<int>> max_half;
    // set two priority queues
    int total;
    int temp;
    /** initialize your data structure here. */
    MedianFinder() {
        total = 0;
    }
    
    void addNum(int num) {
        int min_top,max_top;
        total++;
        if (total == 1){
            temp = num;
            return;
        }
        if (total == 2){
            if (num > temp){
                min_half.push(temp);
                max_half.push(num);
            }
            else{
                min_half.push(num);
                max_half.push(temp);
            }
        }
        if ((total > 2) &&(total%2 == 1)){
            int min_top = min_half.top();
            int max_top = max_half.top();
            if (num <= max_top){
                min_half.push(num);    
            }
            else{
                min_half.push(max_top);
                max_half.pop();
                max_half.push(num);
            }
        }
        if ((total > 2)&&(total%2 == 0)){
            int min_top = min_half.top();
            int max_top = max_half.top();
            if (num >= min_top){
                max_half.push(num);
            }
            else{
                max_half.push(min_top);
                min_half.pop();
                min_half.push(num);
            }
        }
        return;
    }
    
    double findMedian() {
        if (total == 1){
            return temp;
        }
        if (total%2 == 0){
         return (min_half.top()+max_half.top())/2.0f;        
        }
        else{
            return min_half.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */