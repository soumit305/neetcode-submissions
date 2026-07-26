class Solution {
private:
    bool dfsCheckCycle(int node, vector<int>& pathVisited, vector<int>& visited, vector<vector<int>>& adjList){
        visited[node] = 1;
        pathVisited[node] = 1;
        for (int adjacentNode : adjList[node]){
            if (!visited[adjacentNode]){
                if (dfsCheckCycle(adjacentNode, visited, pathVisited, adjList)) return true;
            }
            else if (pathVisited[adjacentNode]) return true;
        }
        pathVisited[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
        for (int i = 0; i<prerequisites.size(); i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int i = 0; i<numCourses ; i++){
            if (!visited[i] && dfsCheckCycle(i,pathVisited,visited,adjList)){
                return false;
            }
        }
        return true;
    }
};
