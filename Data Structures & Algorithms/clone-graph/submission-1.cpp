/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* root) {
        if (root==NULL) return NULL;
        unordered_map<Node*,Node*> mpp;
        dfs(root,mpp);
        for (auto it : mpp){
            Node* node = it.first;
            Node* copy = it.second;
            for (Node* neighbor : node->neighbors){
                copy->neighbors.push_back(mpp[neighbor]);
            }
        }
        return mpp[root];
    }
    void dfs(Node* node, unordered_map<Node*,Node*>& mpp){
        mpp[node] = new Node(node->val);
        for (Node* neighbor : node->neighbors){
            if (mpp.find(neighbor)==mpp.end()){
                dfs(neighbor,mpp);
            }
        }
    }
};
