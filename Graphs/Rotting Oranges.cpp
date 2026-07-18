//Using BFS to find the minimum time required for all fresh oranges to rot in a grid.
//Time Complexity: O(m*n) where m is the number of rows and n is the number of columns in the grid.
// We are visiting each cell in the grid once during the BFS traversal. 
//Space Complexity: O(m*n) for the queue used in BFS, which can take up to O(m*n) space in the worst case when all cells are rotten and added to the queue at once.

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>>rotten;
        int fresh=0;
        int time=0;
        int r = grid.size();
        int c = grid[0].size();

        for(int i=0; i<r; i++){
            for(int j=0;j<c; j++){
                if(grid[i][j] == 1)
                    fresh++;
                else if(grid[i][j] == 2)
                    rotten.push({i,j});
            }
        }

        while(fresh>0 and !rotten.empty()){
            int length = rotten.size();

            for(int p=0;p<length; p++){
                auto curr = rotten.front();
                rotten.pop();
                int i = curr.first;
                int j = curr.second;
                vector<vector<int>>dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
                for(int d=0; d<4; d++){
                    int m = i + dir[d][0];
                    int n = j + dir[d][1];
                    if(m>=0 && n>=0 && m<r && n<c && grid[m][n]==1){
                        grid[m][n]=2;
                        fresh--;
                        rotten.push({m,n});
                    }
                }
            }
            time++;            
        }

        return fresh>0 ? -1: time;
    }
};