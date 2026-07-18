//My Solution using DFS:
//Time Complexity: O(V+E) where V is the number of vertices (courses) and E is the number of edges (prerequisites).
//Space Complexity: O(V+E) for the adjacency list representation of the graph and the visited array.

class Solution {
public:
    unordered_map<int, vector<int>>m;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<bool>visited(numCourses,false);
        for(int i=0;i<prerequisites.size();i++){
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        int i = 0;
        while(i<numCourses){
            if(m.find(i)!=m.end()){
                if(!dfs(visited,i)){
                    return false;
                }    
            }
            i++;
        }
        return true;
    }

    bool dfs(vector<bool>&visited, int start){
        if(m.find(start)==m.end()){
            return true;
        }
        if(visited[start]==true)
            return false;

        visited[start] = true;

        for(auto i:m[start]){
            if(!dfs(visited,i))
                return false;
        }
        visited[start] = false;
        m[start].clear();
        return true;
    }
};

//Better Solution using DFS:
//Time Complexity: O(V+E) where V is the number of vertices (courses) and E is the number of edges (prerequisites).
//Space Complexity: O(V+E) for the adjacency list representation of the graph and the visited set.

class Solution {
public:
    unordered_map<int, vector<int>>m;
    unordered_set<int>visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<numCourses;i++){
            m[i]={};
        }
        for(int i=0;i<prerequisites.size();i++){
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        int i = 0;
        while(i<numCourses){
            if(m.find(i)!=m.end()){
                if(!dfs(i)){
                    return false;
                }    
            }
            i++;
        }
        return true;
    }

    bool dfs(int start){
        if(m[start].empty()){
            return true;
        }
        if(visited.count(start))
            return false;

        visited.insert(start);

        for(auto i:m[start]){
            if(!dfs(i))
                return false;
        }
        visited.erase(start);
        m[start].clear();
        return true;
    }
};

//Using Kahn's Algorithm (BFS) to detect cycle in directed graph:
//Time Complexity: O(V+E) where V is the number of vertices (courses) and E is the number of edges (prerequisites).
//Space Complexity: O(V+E) for the adjacency list representation of the graph and the in-degree array.  

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        unordered_map<int, vector<int>>m;
        for(int i=0;i<prerequisites.size(); i++){
            indegree[prerequisites[i][0]]++;
            m[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }

        int finished=0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            finished++;
            for(int i:m[curr]){
                indegree[i]--;
                if(indegree[i]==0)
                    q.push(i);
            }
        }

        return finished==numCourses?true:false;
    }
};