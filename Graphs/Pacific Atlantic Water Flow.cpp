// Using DFS to find the cells in a grid that can reach both the Pacific and Atlantic oceans based on their heights.
// Time Complexity: O(m*n) where m is the number of rows and n is the number of columns in the grid.
// We are visiting each cell in the grid once during the DFS traversal for both oceans.
// Space Complexity: O(m*n) for the visited arrays used to keep track of cells that can reach the Pacific and Atlantic oceans, which can take up to O(m*n) space in the worst case when all cells are reachable from both oceans.

class Solution {
public:
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int i, int j, int m, int n, vector<vector<bool>>&visited, vector<vector<int>>& heights){
        if(m<0 || n<0 || m>=heights.size() || n>=heights[0].size() || visited[m][n]==true ||heights[m][n]<heights[i][j]){
            return;
        }

        visited[m][n]=true;

        for(int d=0;d<4;d++){
            dfs(m,n,m+dir[d][0], n+dir[d][1], visited, heights);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>>pacific(heights.size(), vector<bool>(heights[0].size(),false));
        vector<vector<bool>>atlantic(heights.size(), vector<bool>(heights[0].size(),false));
        vector<vector<int>>result;
        int r = heights.size();
        int c = heights[0].size();
        for(int i=0;i<r; i++){
            for(int j=0; j<c; j++){
                if(i==0 || j==0){
                    dfs(i,j,i,j,pacific,heights);
                }
            }
        }

        for(int i=0;i<r; i++){
            for(int j=0; j<c; j++){
                if(i==r-1 || j==c-1){
                    dfs(i, j, i, j,  atlantic, heights);
                }
            }
        }

        for(int i=0; i<pacific.size(); i++){
            for(int j=0; j<pacific[0].size(); j++){
                if(pacific[i][j]==true && atlantic[i][j]==true)
                    result.push_back({i, j});
            }
        }

        return result;
    }
};

