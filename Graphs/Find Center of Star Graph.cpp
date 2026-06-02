// My solution:
// Time Complexity: O(n) where n is the number of edges. 
// We iterate through the edges array once to build the edgeCount map, and then we iterate through the edgeCount map once to find the center.
// Space Complexity: O(n) for the edgeCount map.

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int>edgeCount;

        for(auto e: edges){
            edgeCount[e[0]]++;
            edgeCount[e[1]]++;
        }
        int n = edgeCount.size();
        for(auto i:edgeCount){
            if(i.second==n-1)
                return i.first;
        }

        return 0;
    }
};

// My solution2: 
// Time Complexity: O(n) where n is the number of edges.
// We iterate through the edges array once to build the edgeCount vector, 
// and then we iterate through the edgeCount vector once to find the center.
// Space Complexity: O(n) for the edgeCount vector.
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int>edgeCount(edges.size()+2, 0);

        for(auto e: edges){
            edgeCount[e[0]]++;
            edgeCount[e[1]]++;
        }
        for(int i=1; i<edgeCount.size(); i++){
            if(edgeCount[i]==edges.size())
                return i;
        }

        return 0;
    }
};