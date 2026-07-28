class MedianFinder {
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (!maxheap.empty() && maxheap.top()>num){
            maxheap.push(num);
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else {
            minheap.push(num);
        }
        if (minheap.size()>maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if (minheap.size()==maxheap.size()) {
            return ((double)minheap.top() + (double)maxheap.top())/(double)2;
        }
        else return (double)maxheap.top();
    }
};
