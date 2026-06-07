// Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph. 
// We are traversing through all the vertices and edges once in the worst case.
// Building adjacency list: O(E) as we are iterating through the edges to build the adjacency list.
// DFS traversal: O(V + E) as we may visit all the vertices and edges in the worst case during the DFS traversal.
// Total: O(V + E) as we are doing both building the adjacency list and DFS traversal.
// Space Complexity: O(V) where V is the number of vertices in the graph. 
// We are using an adjacency list to store the graph and a visited set to keep track of the visited vertices.    

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>conn(n);

        for(int i=0;i<edges.size();i++){
            conn[edges[i][0]].push_back(edges[i][1]);
            conn[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_set<int>visited;
        return dfs(source, destination, conn, visited);

        
    }

    bool dfs(int node, int destination, vector<vector<int>>& conn, unordered_set<int>& visited){
        if(node == destination)
            return true;
        
        visited.insert(node);

        for(auto neighbor: conn[node]){
            if(visited.find(neighbor) == visited.end()){
                if(dfs(neighbor, destination, conn, visited)){
                    return true;
                }
            }
        }

        return false;
    }
};