//My solution using Topological Sort (Kahn's Algorithm):
//Time Complexity: O(V+E) where V is the number of vertices (courses) and E is the number of edges (prerequisites).
//Space Complexity: O(V+E) for the adjacency list representation of the graph and the in-degree array.
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses, 0);
        unordered_map<int, vector<int>>m;

        for(auto& pre:prerequisites){
            indegree[pre[0]]++;
            m[pre[1]].push_back(pre[0]);
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
            q.push(i);
        }
        vector<int>order;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            order.push_back(curr);
            for(int i:m[curr]){
                indegree[i]--;
                if(indegree[i]==0)
                    q.push(i);
            }
        }a

        if(order.size()==numCourses){
            return order;
        }
        else
            return {};
    }
};

//Using DFS to detect cycle in directed graph
//Time Complexity: O(V+E) where V is the number of vertices (courses) and E is the number of edges (prerequisites).
//Space Complexity: O(V+E) for the adjacency list representation of the graph and the visited set.
class Solution {
public:
    unordered_map<int, vector<int>>m;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        for(int i=0;i<numCourses;i++){
            m[i]={};
        }
        for(auto& pre:prerequisites){
            m[pre[0]].push_back(pre[1]);
        }
        unordered_set<int>visited;
        unordered_set<int>cycle;
        vector<int>output;
        for(int i=0;i<numCourses;i++){
            if(!dfs(i, visited, cycle, output))
                return {};
        }
        return output;
    }

    bool dfs(int course, unordered_set<int>& visited, unordered_set<int>& cycle, vector<int>& output){
        if(cycle.count(course)){
            return false;
        }
        if(visited.count(course)){
            return true;
        }
        cycle.insert(course);

        if(!m[course].empty()){
            for(int pre:m[course]){
                if(!dfs(pre, visited, cycle, output))
                    return false;
            }
        }
        cycle.erase(course);
        visited.insert(course);
        output.push_back(course);
        return true;
    }  
};


