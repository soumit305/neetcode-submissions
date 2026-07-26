class DisjointSet{
public:
    vector<int> size,parent;
    DisjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for (int i = 0; i<n; i++) parent[i] = i;
    }
    int findUPar(int node){
        if (node==parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int ultu = findUPar(u);
        int ultv = findUPar(v);
        if (ultu == ultv) return;
        if (size[ultu]>size[ultv]){
            parent[ultv] = ultu;
            size[ultu] += size[ultv];
        } else {
            parent[ultu] = ultv;
            size[ultv] += size[ultv];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n+1);
        for (auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int ultu = ds.findUPar(u);
            int ultv = ds.findUPar(v);
            if (ultu == ultv) return {u,v};
            ds.unionBySize(u,v);
        }
        return {};
    }
};
