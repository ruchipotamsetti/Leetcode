// My solution:
// Time Complexity: O(n^2) where n is the number of vertices in the graph.
// We have two nested loops, the outer loop iterates through the vertices and the inner loop iterates through the adjacency matrix to count the degree of each vertex.
// Space Complexity: O(n) where n is the number of vertices in the graph.

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>ans(n, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j)
                    continue;
                if(matrix[i][j] == 1){
                    ans[i]++;
                }
            }
        }

        return ans;
    }
};