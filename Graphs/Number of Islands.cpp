// Time Complexity: O(m*n) where m is the number of rows and n is the number of columns in the grid.
// We are traversing through all the cells in the grid once in the worst case.      
// Space Complexity: O(m*n) in the worst case when the grid is filled with land and we have to visit all the cells in the grid during the DFS traversal.

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size(); 
        int islands = 0; 
        for(int i=0;i<m; i++){ 
            for(int j=0;j<n; j++){ 
                if(grid[i][j]=='1'){ 
                    islands++; 
                    dfs(i, j, grid); 
                } 
            } 
        } 
        
        return islands;
    }

    void dfs(int row, int col, vector<vector<char>>& grid){ 
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == '0'){ 
            return; 
        } 
        grid[row][col] = '0'; 

        dfs(row-1, col, grid); 
        dfs(row+1, col, grid); 
        dfs(row, col-1, grid); 
        dfs(row, col+1, grid); 
    }
};