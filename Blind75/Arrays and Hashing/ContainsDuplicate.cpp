// Brute Force(Time exceeds): O(n^2)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n= nums.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] == nums[j])
                    return true;
            }
        }

        return false;

    }
};

// Solution 1: O(nlogn)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1])
                return true;
        }
        return false;
    }
};

// Solution 2: O(n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int>cnt;
        for(int value:nums){
            cnt[value]++;
        }
        for(auto pair:cnt){
            if(pair.second>1)
                return true;
        }

        return false;
    }
};

