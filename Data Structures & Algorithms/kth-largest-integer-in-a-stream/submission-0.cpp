class KthLargest {
private:
    priority_queue<int> pq;
    stack<int> st;
    int kValue;
public:
    KthLargest(int k, vector<int>& nums) {
        for (int num : nums){
            pq.push(num);
        }
        kValue = k;
    }
    
    int add(int val) {
        pq.push(val);
        for (int i = 0; i<kValue-1; i++){
            st.push(pq.top());
            pq.pop();
        }
        int ans = pq.top();
        while (!st.empty()){
            pq.push(st.top());
            st.pop();
        }
        return ans;
    }
};
