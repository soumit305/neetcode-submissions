class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if (n==1) return stones[0];
        priority_queue<int> pq;
        for (int stone : stones){
            pq.push(stone);
        }
        while(pq.size()>1){
            int stone1 = pq.top(); pq.pop();
            int stone2 = pq.top(); pq.pop();
            if (stone1 == stone2) continue;
            else pq.push(stone1-stone2);
        }
        return (pq.empty()) ? 0 : pq.top();
    }
};
