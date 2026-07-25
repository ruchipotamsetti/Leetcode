//Using Disjoint Set Union (DSU) or Union-Find:
//Time Complexity: O(E * α(V)) where E is the number of edges and α is the inverse Ackermann function, which is very slow-growing and can be considered nearly constant for practical purposes.
//Where V is the number of vertices and E is the number of edges in the graph.
//Space Complexity: O(V) for the parent and rank arrays.

class DSU{
public:
    vector<int>parent;
    vector<int>rank;
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1, 1);
        for(int i=0;i<=n; i++){
            parent[i]=i;
        }
    }

    int find(int node){
        int res = node;
        while(res!=parent[res])
        {
            parent[res] = parent[parent[res]];
            res = parent[res];
        }

        return res;
    }

    bool unionSets(int n1, int n2){
        int p1 = find(n1);
        int p2 = find(n2);

        if(p1 == p2)
            return false;

        if(rank[p1]>rank[p2]){
            parent[p2]=p1;
            rank[p1] += rank[p2];
        }
        else{
            parent[p1]=p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());

        for(auto edge:edges){
            if(!dsu.unionSets(edge[0], edge[1])){
                return {edge[0], edge[1]};
            }
        }

        return {};
    }
};