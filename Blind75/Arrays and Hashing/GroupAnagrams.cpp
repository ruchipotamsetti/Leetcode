// Brute Force

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> cpy = strs;
        unordered_set<string>viewed;
        vector<vector<string>>result;
        int n = cpy.size();
        for(int i=0; i<n; i++){
            sort(cpy[i].begin(), cpy[i].end());
        }
        vector<string>group;
        for(int i=0; i<n; i++){
            if(viewed.find(cpy[i]) == viewed.end()){
                viewed.insert(cpy[i]);
                group.push_back(strs[i]);
                for(int j=i+1; j<n; j++){
                    if(cpy[i] == cpy[j])
                        group.push_back(strs[j]);
                }
                result.push_back(group);
                group.clear();
            }
        }
        return result;
    }
};

// Optimized solution:

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> result;
        for(auto x:strs){
            string key = x;
            sort(key.begin(), key.end());
            mp[key].push_back(x);
        }

        for(auto x: mp){
            result.push_back(x.second);
        }
        return result;
    }
};