//My Solution using DFS:
// Time Complexity: O(m*n) where m is the number of rows and n is the number of columns in the grid.
// We are visiting each cell in the grid once during the DFS traversal for both oceans.
// Space Complexity: O(m*n) for the visited arrays used to keep track of cells that can reach the Pacific and Atlantic oceans, which can take up to O(m*n) space in the worst case when all cells are reachable from both oceans.

class Solution {
public:
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    if(board[i][j]=='O')
                        dfs(i, j, board, visited);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && visited[i][j]==false){
                    board[i][j]='X';
                }
            }
        }
    }

    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='X' || visited[i][j]==true){
            return;
        }
        visited[i][j]=true;
        for(int d=0;d<4;d++){
            dfs(i+dir[d][0], j+dir[d][1], board, visited);
        }
    }
};

//Better solution using DFS:
// Time Complexity: O(m*n) where m is the number of rows and n is the number of columns in the grid.
// We are visiting each cell in the grid once during the DFS traversal for both oceans.
// Space Complexity: O(m*n) for the recursion stack in the worst case when all cells are land and we have to traverse all of them.

class Solution {
public:
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    if(board[i][j]=='O')
                        dfs(i, j, board);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }

    void dfs(int i, int j, vector<vector<char>>& board){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='X' || 
        board[i][j]=='#'){
            return;
        }
        board[i][j]='#';
        for(int d=0;d<4;d++){
            dfs(i+dir[d][0], j+dir[d][1], board);
        }
    }
};

//Can be solved using BFS as well:
// Time Complexity: O(m*n) where m is the number of rows and n is the number of columns in the grid.
// We are visiting each cell in the grid once during the BFS traversal for both oceans.
// Space Complexity: O(m*n) for the queue used in BFS, which can take up to O(m*n) space in the worst case when all cells are reachable from both oceans.

class Solution {
public:
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    if(board[i][j]=='O')
                        q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;
            board[i][j] = '#';
            for(int d=0;d<4;d++){
                int r = i + dir[d][0];
                int c = j + dir[d][1];
                if(r<0 || c<0 || r>=m || c>=n || board[r][c]=='X' || board[r][c]=='#'){
                    continue;
                }
                q.push({r,c});
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};