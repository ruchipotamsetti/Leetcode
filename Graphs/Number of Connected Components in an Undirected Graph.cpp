//My Solution using DFS:
// Time Complexity: O(V+E) where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V+E) for the adjacency list representation of the graph and the visited set.

class Solution {
public:
    unordered_set<int>visited;
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>m;

        for(int i=0;i<n;i++){
            m[i] = {};
        }

        for(auto e:edges){
            m[e[0]].push_back(e[1]);
            m[e[1]].push_back(e[0]);
        }

        int connected = 0;
        for(int i=0;i<n;i++){
            if(!visited.count(i)){
                connected++;
                dfs(i, m);
            }
        }

        return connected;
    }

    void dfs(int node, unordered_map<int, vector<int>>&m){
        if(visited.count(node))
            return;

        visited.insert(node);

        for(int nei:m[node]){
            if(!visited.count(nei))
                dfs(nei, m);
        }

        return;
    }
};

// Using Disjoint Set Union (DSU) or Union-Find:
// Time Complexity: O(E * α(V)) where E is the number of edges and α is the inverse Ackermann function, which is very slow-growing and can be considered nearly constant for practical purposes.    
//Where V is the number of vertices and E is the number of edges in the graph. α() is used for amortized complexity.
// Space Complexity: O(V) for the parent and rank arrays.

class DSU{
public:
    vector<int>parent;
    vector<int>rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    } 

    int find(int node){
        int res = node;
        while(res != parent[res]){
            parent[res] = parent[parent[res]];
            res = parent[res];
        }
        return res;
    }

    bool unionSets(int n1, int n2){
        int p1 = find(n1);
        int p2 = find(n2);

        if(p1==p2)
            return false;

        if(rank[p1]>rank[p2]){
            parent[p2]=p1;
            rank[p1]+=rank[p2];
        }
        else{
            parent[p1]=p2;
            rank[p2]+=rank[p1];
        }
        return true;   
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int res = n;
        for(auto e:edges){
            if(dsu.unionSets(e[0], e[1]))
                res--;
        }
        return res;
    }
};


