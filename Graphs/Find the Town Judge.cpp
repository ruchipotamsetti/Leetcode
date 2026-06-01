//My Solution:
//Time Complexity: O(n) where n is the number of trust relationships. We iterate through the trust array once to build the connection and trustSomeone arrays, and then we iterate through the connection array once to find the judge.
//Space Complexity: O(n) for the connection and trustSomeone arrays.
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool>trustsSomeone(n, false);
        vector<vector<int>>conn(n);

        for(auto t:trust){
            conn[t[1]-1].push_back(t[0]);
            trustsSomeone[t[0]-1] = true;
        }

        for(int i=0;i<conn.size(); i++){
            if(conn[i].size() == n-1 && trustsSomeone[i]==false)
                return i+1;
        }

        return -1;
    }
};

//Optimal Solution: Using Indegree and Outdegree in a single array
//Time Complexity: O(n) where n is the number of trust relationships. We iterate through the trust array once to build the indegree and outdegree arrays, and then we iterate through the indegree and outdegree arrays once to find the judge.
//Space Complexity: O(n) for the indegree and outdegree arrays.
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int, int>>conn(n,{0,0});

        for(auto t:trust){
            conn[t[1]-1].first +=1;
            conn[t[0]-1].second +=1;
        }

       for(int i=0; i<n; i++){
        if(conn[i].first - conn[i].second == n-1)
            return i+1;
       }

        return -1;
    }
};

//Optimal Solution2: Using Indegree and Outdegree with separate arrays
//Time Complexity: O(n) where n is the number of trust relationships. We iterate through the trust array once to build the indegree and outdegree arrays, and then we iterate through the indegree and outdegree arrays once to find the judge.
//Space Complexity: O(n) for the indegree and outdegree arrays.
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indegree(n+1,0);
        vector<int>outdegree(n+1,0);

        for(auto t: trust){
            outdegree[t[0]]++;
            indegree[t[1]]++;
        }

        for(int i=1;i<n+1; i++){
            if(indegree[i]==n-1 && outdegree[i]==0)
                return i;
        }

        return -1;
    }
};