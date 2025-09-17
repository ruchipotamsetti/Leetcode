// Brute Force

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n =nums.size();
        for(int i=0; i<n-1; i++){
            int diff = target - nums[i];
            for(int j=i+1; j<n; j++){
                if(diff ==  nums[j])
                    return {i,j};
            }
        }
        return {0,0};
    }
};

// Solution 1

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n =nums.size();
        unordered_map<int, int>indices;
        for(int i=0; i<n; i++){
            indices[nums[i]] = i;
        }
        for(int i=0; i<n; i++){
            int diff = target -nums[i];
            if(indices.find(diff) != indices.end() && i != indices[diff])
                return {i, indices[diff]};
        }
        return {0,0};
    }
};

// Solution 1 modified

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n =nums.size();
        unordered_map<int, int>indices;
        for(int i=0; i<n; i++){
            int diff = target -nums[i];
            if(indices.find(diff) != indices.end())
                return {indices[diff], i};
            indices[nums[i]] = i;
        }
        return {};
    }
};