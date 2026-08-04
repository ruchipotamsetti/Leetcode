//Using Kahn's Algorithm(Topological Sort)
//Time Complexity: O(N+V+E) Where V is the number of unique characters, E is the number of edges and N is the sum of lengths of all the strings.
//Space Complexity: O(V+E) Where V is the number of unique characters and E is the number of edges.

class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>>adj;
        unordered_map<char, int>indegree;

        for(auto w: words){
            for(char c: w){
                adj[c] = unordered_set<char>();
                indegree[c]=0;
            }
        }

        for(int i=0; i<words.size()-1; i++){
            string w1 = words[i];
            string w2 = words[i+1];

            int minLen = min(w1.size(), w2.size());
            if(w1.size()>w2.size() && w1.substr(0, minLen) == w2.substr(0, minLen)){
                return "";
            }

            for(int j=0;j<minLen;j++){
                if(w1[j]!=w2[j]){
                    if(!adj[w1[j]].count(w2[j])){
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }


        queue<char>q;
        for(auto [c,d]:indegree){
            if(d==0){
                q.push(c);
            }
        }

        string res = "";
        while(!q.empty()){
            char c = q.front();
            q.pop();
            res += c;
            
            for(auto nei:adj[c]){
                indegree[nei]--;
                if(indegree[nei]==0)
                    q.push(nei);
            }
            
        }

        return res.size()==indegree.size() ? res : "";
        
    }
};
