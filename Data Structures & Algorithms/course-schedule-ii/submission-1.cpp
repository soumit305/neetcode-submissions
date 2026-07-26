class Solution {
private: 
    bool dfs(int node, int parent, vector<int>& visited, vector<int>& pathVisited, vector<vector<int>>& adjList,vector<int>& ans){
        visited[node] = 1;
        pathVisited[node] = 1;
        ans.push_back(node);
        for (int adjacentNode : adjList[node]){
            if (adjacentNode != parent){
                if (!visited[adjacentNode]){
                    return dfs(adjacentNode,node,visited,pathVisited,adjList,ans);
                }
                else if (pathVisited[adjacentNode]) return true;
            }
        }
        pathVisited[node] = 0;
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses,0);
        vector<int> pathVisited(numCourses,0);
        vector<vector<int>> adjList(numCourses);
        for (vector<int> prereq : prerequisites){
            int u = prereq[0];
            int v = prereq[1];
            adjList[v].push_back(u);
        }
        vector<int> ans;
        for (int i = 0; i<numCourses; i++){
            if (!visited[i]){
               if (dfs(i,i,visited,pathVisited,adjList,ans)) return {};
            }
        }
        return ans;
    }
};
