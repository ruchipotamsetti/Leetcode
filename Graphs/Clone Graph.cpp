// Using DFS:
// Time Complexity: O(V+E) where V is the number of vertices and E is the number of edges in the graph. 
// We are visiting each vertex and edge once during the DFS traversal.
// Space Complexity: O(V) where V is the number of vertices in the graph. 
// We are using a hash map to store the mapping of old nodes to new nodes, which can take up to O(V) space in the worst case when all nodes are connected. Additionally, the recursive call stack can also take up to O(V) space in the worst case when the graph is a linear chain of nodes.
class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& oldToNew){
        
        if(oldToNew.count(node)){
            return oldToNew[node];
        }

        Node* copy = new Node(node->val);
        oldToNew[node]  = copy;

        for(Node* nei: node->neighbors){
            copy->neighbors.push_back(dfs(nei, oldToNew));
        }

        return copy;
    }
    
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        unordered_map<Node*, Node*>oldToNew;
        return dfs(node, oldToNew);
    }
};


// Using BFS:
// Time Complexity: O(V+E) where V is the number of vertices and E is the number of edges in the graph. 
// We are visiting each vertex and edge once during the BFS traversal.
// Space Complexity: O(V) where V is the number of vertices in the graph. 
// We are using a hash map to store the mapping of old nodes to new nodes, which can take up to O(V) space in the worst case when all nodes are connected. Additionally, the queue used for BFS can also take up to O(V) space in the worst case when all nodes are connected and added to the queue at once.    

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;

        unordered_map<Node*, Node*>oldToNew;
        queue<Node*>q;
        oldToNew[node] = new Node(node->val);
        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            for(Node* nei: curr->neighbors){
                if(oldToNew.find(nei)==oldToNew.end()){
                    oldToNew[nei] = new Node(nei->val);
                    q.push(nei);
                }
                oldToNew[curr]->neighbors.push_back(oldToNew[nei]);
            }
        }

        return oldToNew[node];
    }
};