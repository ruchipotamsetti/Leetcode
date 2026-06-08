// My solution: Use DFS to explore the island and calculate its area. Update the maximum area found so far.
// Time Complexity: O(m*n) where m is the number of rows and n is the number of columns in the grid.
// We are traversing through all the cells in the grid once in the worst case.  
// Space Complexity: O(m*n) in the worst case when the grid is filled with land and we have to visit all the cells in the grid during the DFS traversal.

class Solution {
public:
    int maxArea=0;
    int area = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0; i<m; i++){
            for(int j=0;j<n; j++){
                if(grid[i][j]==1){
                    area = 0;
                    int currArea = dfs(i, j, grid);
                    maxArea = max(maxArea, currArea);
                }   
            }
        }
        return maxArea;
    }

    int dfs(int r, int c, vector<vector<int>>& grid){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c] == 0){
            return area;
        }

        grid[r][c] = 0;
        area++;

        dfs(r+1, c, grid);
        dfs(r-1, c, grid);
        dfs(r, c+1, grid);
        dfs(r, c-1, grid);

        return area;

    }
};