class Solution {
private: 
    bool dfs(int node, vector<int>& visited, vector<int>& pathVisited, vector<vector<int>>& adjList,vector<int>& ans){
        visited[node] = 1;
        pathVisited[node] = 1;
        for (int adjacentNode : adjList[node]){
            if (!visited[adjacentNode]){
                if (dfs(adjacentNode,visited,pathVisited,adjList,ans)) return true;
            }
            else if (pathVisited[adjacentNode]) return true;
        }
        ans.push_back(node);
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
               if (dfs(i,visited,pathVisited,adjList,ans)) return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
