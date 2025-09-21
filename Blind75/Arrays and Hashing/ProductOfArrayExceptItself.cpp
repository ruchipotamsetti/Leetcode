// Solution 1:

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n, 1);
        vector<int>suffix(n, 1);
        int prod = prefix[0];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        prod = suffix[n-1];
        for(int i=n-2; i>=0; i--){
            suffix[i] = suffix[i+1] * nums[i+1];
            prod = suffix[i];
        }
        vector<int>result;
        for(int i=0; i<n; i++){
            result.push_back(prefix[i] * suffix[i]);
        }
        return result;
    }
};

// Solution 2:

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n, 1);
       
        for(int i=1; i<n; i++){
            result[i] = result[i-1] * nums[i-1];
        }

        int suffix = 1;
        for(int i=n-2; i>=0; i--){
            suffix *= nums[i+1];
            result[i] = result[i] * suffix;
        }

        return result;
    }
};

// Simplified Solution 2:

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
       
        vector<int>result(n,1);

        int current = 1;
        for(int i=0; i<n; i++){
            result[i] *= current;
            current *= nums[i];
        }

        current = 1;
        for(int i=n-1; i>=0; i--){
            result[i] *= current;
            current *= nums[i];
        }

        return result;
    }
};