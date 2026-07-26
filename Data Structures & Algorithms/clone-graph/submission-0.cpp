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
        if (root == NULL) return NULL;

        queue<Node*> q;
        vector<int> visited(101,0);
        q.push(root);
        visited[1] = 1;
        Node* newRoot;

        while(!q.empty()){
            Node* node = q.front(); q.pop();
            Node* newNode = new Node(node->val,node->neighbors);
            if (node==root) newRoot = newNode;
            for (Node* adjacentNode : node->neighbors){
                if (!visited[adjacentNode->val]){
                    q.push(adjacentNode);
                    visited[adjacentNode->val] = 1;
                }
            } 
        }
        return newRoot;
    }
};
