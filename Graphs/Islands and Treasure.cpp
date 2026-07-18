// Using DFS to find the shortest distance from each land cell to the nearest treasure cell in a grid.

//Time Complexity: O((m*n)^2) where m is the number of rows and n is the number of columns in the grid. 
// Because in the worst case, we may have to traverse all cells for each land cell to find the nearest treasure cell.
//Space Complexity: O(m*n) for the recursion stack in the worst case when all cells are land and we have to traverse all of them.

class Solution {
public:
    const int INF = 2147483647;
    vector<vector<int>>dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    for(int k=0; k<4;k++){
                        dfs(i+dir[k][0], j+dir[k][1], grid, 1);
                    }
                }
            }
        }   
    }

    void dfs(int i, int j, vector<vector<int>>& grid, int dist){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1 || grid[i][j]==0)
            return;

        if(grid[i][j]>dist){
            grid[i][j] = dist;
        }
        else{
            return;
        }

        for(int k=0; k<4;k++){
            dfs(i+dir[k][0], j+dir[k][1], grid, dist+1);
        }
    }
};
