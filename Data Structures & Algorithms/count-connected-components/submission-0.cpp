class DisjointSet{
public:
    vector<int> parent,size;
    DisjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for (int i = 0; i<n; i++) parent[i] = i;
    }
    int findUPar(int node){
        if (node == parent[node]) return node;
        else return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int ultu = findUPar(u);
        int ultv = findUPar(v);
        if (size[ultu]>size[ultv]){
            parent[v] = ultu;
            size[ultu] += size[ultv];
        } else {
            parent[u] = ultv;
            size[ultv] += size[ultu]; 
        }
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for (auto it : edges){
            ds.unionBySize(it[0],it[1]);
        }
        int numConnected = 0;
        for (int i = 0 ; i<n; i++){
            if (ds.parent[i]==i) numConnected++;
        }
        return numConnected;
    }
};
