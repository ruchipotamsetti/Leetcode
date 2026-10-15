//My solution:
// Time Complexity: O(n^2) where n is the size of the input array.
// Space Complexity: O(n) as we are using a set to store the distinct elements of the subarray.
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        unordered_set<int>subarray;

        for(int i=0;i<n;i++){
            
            for(int j=i;j<n;j++){
                subarray.insert(nums[j]);
                int size = subarray.size();
                result += size*size;
            }
            subarray.clear();
        }

        return result;
    }
};

// Better logic:
// Time Complexity: O(n^2) where n is the size of the input array.
// Space Complexity: O(n) as we are using a set to store the distinct elements of the subarray.
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for(int i=0;i<n;i++){
            unordered_set<int>subarray;
            for(int j=i;j<n;j++){
                subarray.insert(nums[j]);
                int size = subarray.size();
                result += size*size;
            }
        }

        return result;
    }
};

// Improved space complexity:
// Time Complexity: O(n^2) where n is the size of the input array.
// Space Complexity: O(1) as we are using a fixed size array to store the distinct elements of the subarray.

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        
        for(int i=0;i<n;i++){
            bool check[101]={false};
            int distinct=0;
            for(int j=i;j<n;j++){
                if(!check[nums[j]]){
                    check[nums[j]] = true;
                    distinct++;
                }
                result += distinct*distinct;
            }
        }

        return result;
    }
};

