//Using Hierholzer's algorithm to find an Eulerian path in a directed graph. 
// The algorithm constructs the itinerary by performing a depth-first search (DFS) on the graph, 
// starting from the "JFK" airport. The adjacency list is implemented using a priority queue to ensure that the next destination is chosen in lexicographical order.:

//Time Complexity: O(E log E) where E is the number of edges (tickets) in the graph. The priority queue operations take logarithmic time.
//Space Complexity: O(V + E) for the adjacency list representation of the graph and the itinerary vector, 
//where V is the number of vertices (airports) and E is the number of edges (tickets).

// This problem is an Eulerian Path problem:
// we must use every ticket exactly once and form a valid path starting from "JFK".

//Hierholzer's Algorithm builds such a path by:
// -> always taking an available edge,
// -> going as deep as possible,
// -> and adding airports to the answer only when no outgoing edges remain

class Solution {
public:
    vector<string>itinerary;
    unordered_map<string, priority_queue<string, vector<string>, greater<>>>adj;
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for(auto ticket: tickets){
            adj[ticket[0]].push(ticket[1]);
        }

        dfs("JFK");
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }

    void dfs(string city){

        while(!adj[city].empty()){
            string next = adj[city].top();
            adj[city].pop();
            dfs(next);
        }
        itinerary.push_back(city);
    }
};