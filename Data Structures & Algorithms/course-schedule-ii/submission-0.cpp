class Solution {
private: 
    bool dfs(int node, int parent, vector<int>& visited, vector<vector<int>>& adjList,vector<int>& ans){
        visited[node] = 1;
        ans.push_back(node);
        for (int adjacentNode : adjList[node]){
            if (adjacentNode != parent){
                if (!visited[adjacentNode]){
                    return dfs(adjacentNode,node,visited,adjList,ans);
                }
                else{
                    return true;
                }
            }
        }
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses,0);
        vector<vector<int>> adjList(numCourses);
        for (vector<int> prereq : prerequisites){
            int u = prereq[0];
            int v = prereq[1];
            adjList[v].push_back(u);
        }
        vector<int> ans;
        for (int i = 0; i<numCourses; i++){
            if (!visited[i]){
               if (dfs(i,i,visited,adjList,ans)) return {};
            }
        }
        return ans;
    }
};
