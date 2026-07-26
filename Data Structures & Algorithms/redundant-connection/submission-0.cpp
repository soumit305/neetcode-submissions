class Solution {
private:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adjList, vector<int>& ans){
        visited[node] = 1;
        for (int adjacentNode : adjList[node]){
            if (!visited[adjacentNode]){
                dfs(adjacentNode,visited,adjList,ans);
            }
            else {
                if (ans.empty()){
                    ans.push_back(node);
                    ans.push_back(adjacentNode);
                } else {
                    ans[0] = node;
                    ans[1] = adjacentNode;
                }
            }
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // int n = edges.size();
        // vector<int> visited(n+1,0);
        // vector<vector<int>> adjList(n+1);
        // for (vector<int> edge : edges){
        //     adjList[edge[0]].push_back(edge[1]);
        //     adjList[edge[1]].push_back(edge[0]);
        // }
        // vector<int> ans;
        // dfs(1,visited,adjList,ans);
        // return ans;

        int n = edges.size();
        vector<int> visited(n+1,0);
        for (auto edge : edges){
            int firstNode = edge[0];
            int secondNode = edge[1];
            if (visited[firstNode] && visited[secondNode]) return {firstNode,secondNode};
            visited[firstNode] = 1;
            visited[secondNode] = 1;
        }
        return {};
    }
};
