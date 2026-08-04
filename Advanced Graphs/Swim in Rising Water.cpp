// My Solution using Dijkstra's Algorithm
//Time Complexity: O(N^2 log N) where N is the size of the grid. Each cell is processed once, and we use a priority queue to get the minimum time cell, which takes logarithmic time.
//Space Complexity: O(N^2) for the adjacency list representation of the graph and the priority queue.

class Solution {
public:
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        map<pair<int,int>, vector<vector<int>>>adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<4;k++){
                    int a = i +  dir[k][0];
                    int b = j + dir[k][1];
                    if(a<0 || a>=n || b<0 || b>=n){
                        continue;
                    }
                    adj[{i,j}].push_back({a,b});
                }
            }
        }

        priority_queue<array<int,3>, vector<array<int,3>>, greater<>>pq;
        pq.push({grid[0][0],0,0});
        int minTime = INT_MIN;
        int i=0;
        int j=0;
        
        while(!pq.empty()){
            auto [time, i, j] = pq.top();
            pq.pop();
            grid[i][j]=n*n;
            minTime = max(minTime, time);
            if(i==n-1 && j==n-1)
                break;
            for(auto nei:adj[{i,j}]){
                if(grid[nei[0]][nei[1]]==n*n)
                    continue;
                pq.push({grid[nei[0]][nei[1]],nei[0],nei[1]});
            }
        }

        return minTime;
    }
};

//Optimized Solution using Dijkstra's Algorithm
//Removed the adjacency list representation of the graph and used a set to keep track of visited cells instead.
//Time Complexity: O(N^2 log N) where N is the size of the grid. Each cell is processed once, and we use a priority queue to get the minimum time cell, which takes logarithmic time.
//Space Complexity: O(N^2) for the priority queue and the visited set.


class Solution {
public:
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<array<int,3>, vector<array<int,3>>, greater<>>pq;
        pq.push({grid[0][0],0,0});
        set<pair<int, int>> visit;
        visit.insert({0, 0});
        while(!pq.empty()){
            auto [time, i, j] = pq.top();
            pq.pop();
            
            
            if(i==n-1 && j==n-1)
                return time;
            
            for(int k=0;k<4;k++){
                    int a = i +  dir[k][0];
                    int b = j + dir[k][1];
                    if(a<0 || a>=n || b<0 || b>=n || visit.count({a,b})){
                        continue;
                    }
                    visit.insert({a,b});
                    pq.push({max(grid[a][b],time),a,b});
            }
        }

        return 0;
    }
};