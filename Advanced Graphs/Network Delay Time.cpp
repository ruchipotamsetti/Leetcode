//Using DFS:
//Time Complexity: O(V+E) where V is the number of vertices and E is the number of edges in the graph.
//Space Complexity: O(V+E) for the adjacency list representation of the graph and the visited set.

class Solution {
public:
    vector<int>dist;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        dist.resize(n+1, INT_MAX);
        
        unordered_map<int, vector<pair<int, int>>>adj;

        for(int i=0;i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        dfs(k,0,adj);

        int res = *max_element(dist.begin()+1, dist.end());

        return res==INT_MAX ? -1 : res;
    }

    void dfs(int node, int time, unordered_map<int, vector<pair<int, int>>>& adj){
        if(time>=dist[node])
            return;

        dist[node]=time;

        for(auto& [nei, w]: adj[node]){
            dfs(nei, time + w, adj);
        }
    }
};


//uSING Djikstra's Algorithm:
//Time Complexity: O(E log V) where E is the number of edges and V is the number of vertices in the graph. The priority queue operations take logarithmic time.
//Space Complexity: O(V + E) for the adjacency list representation of the graph and the distance array.

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> edges;
        for (const auto& time : times) {
            edges[time[0]].emplace_back(time[1], time[2]);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, k});

        set<int> visited;
        int t = 0;
        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            int w1 = curr.first, n1 = curr.second;
            if (visited.count(n1)) {
                continue;
            }
            visited.insert(n1);
            t = w1;

            if (edges.count(n1)) {
                for (const auto& next : edges[n1]) {
                    int n2 = next.first, w2 = next.second;
                    if (!visited.count(n2)) {
                        minHeap.push({w1 + w2, n2});
                    }
                }
            }
        }

        return visited.size() == n ? t : -1;
    }
};