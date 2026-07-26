class MinStack {
    int minStack[1000];
    int lastIdx;
    int minValues[1000];
    int minIdx;
    int minValue;
public:
    MinStack() {
        lastIdx = -1;
        minIdx = -1;
        minValue = INT_MAX;
    }
    
    void push(int val) {
        minStack[lastIdx+1]=val;
        lastIdx++;
        if (val<=minValue){
            minValue = val;
            minValues[minIdx+1] = val;
            minIdx++;
        }
    }
    
    void pop() {
        if (minStack[lastIdx]==minValues[minIdx]) {
            minIdx--;
            minValue = minValues[minIdx];
        }
        lastIdx--;
    }
    
    int top() {
        return minStack[lastIdx];
    }
    
    int getMin() {
        return minValue;
    }
};
