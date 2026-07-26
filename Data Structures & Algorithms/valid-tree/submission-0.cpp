class Solution {
private: 
    void dfsCheckCycle(int node, vector<int>& visited, vector<vector<int>>& adjList){
        visited[node] = 1;
        for (int adjacentNode : adjList[node]){
            if (!visited[adjacentNode]){
                dfsCheckCycle(adjacentNode,visited,adjList);
            }
        }
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<int> visited(n,0);
        vector<vector<int>> adjList(n);
        for (auto it : edges){
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        dfsCheckCycle(0,visited,adjList);
        for (int i = 0; i<n; i++){
            if (!visited[i]) return false;
        }
        return true;
    }
};
