//Using Kruskal's Algorithm:
//Time Complexity: O(E log E) where E is the number of edges in the graph
//Space Complexity: O(V + E) for the adjacency list representation of the graph and the DSU data structure.


class DSU{
public:
    vector<int>parent;
    vector<int>rank;

    DSU(int n){
        rank.resize(n, 1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find(int node){
        int res = node;

        while(res!=parent[res]){
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

        if(rank[p2]>rank[p1]){
            parent[p1]=p2;
            rank[p2]+=rank[p1];
        }
        else{
            parent[p2]=p1;
            rank[p1]+=rank[p2];
        }

        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<array<int,3>>edges;
        DSU dsu(n);
        for(int i=0;i<n;i++){
            for(int j=i+1; j<n;j++){
                int dist = abs(points[i][0]-points[j][0]) +
                abs(points[i][1]-points[j][1]);
                edges.push_back({dist,i, j});
            }
        }

        sort(edges.begin(), edges.end());
        int minCost=0;

        for(auto [distance, p1, p2]:edges){
            if(dsu.unionSets(p1, p2))
                minCost+=distance;
        }

        return minCost;
    }
};