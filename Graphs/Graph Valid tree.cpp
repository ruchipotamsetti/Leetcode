//Using DFS:
//Time Complexity: O(V+E) where V is the number of vertices (courses) and E is the number of edges (prerequisites).
//Space Complexity: O(V+E) for the adjacency list representation of the graph and the visited set.

class Solution {
public:
    unordered_map<int, vector<int>>m;
    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size()>n-1)
            return false;

        for(int i=0;i<edges.size();i++){
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }

        unordered_set<int>visited;
        if(!dfs(0,-1,visited))
            return false;
        
        return visited.size()==n;
    }

    bool dfs(int node, int parent, unordered_set<int>& visited){

        if(visited.count(node))
            return false;

        visited.insert(node);
        for(auto i:m[node]){
            if(i==parent)
                continue;
            if(!dfs(i, node, visited)){
                return false;
            }
        }
        return true;
    }
};
