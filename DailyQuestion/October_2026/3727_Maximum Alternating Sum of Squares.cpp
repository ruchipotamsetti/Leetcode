//My solution:
//Time Complexity: O(nlogn) where n is the size of the input vector nums. 
// We sort the vector which takes O(nlogn) time and then iterate through the vector once, performing constant time operations for each element.
//Space Complexity: O(1) as we are using a constant amount of extra space.

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                nums[i] *= (-1);
            }
        }
        sort(nums.begin(), nums.end());

        int i=0;
        int j=n-1;

        while(i<=j){
            if(i==j){
                result += (nums[i]*nums[i]);
            }
            else{
                result += (nums[j]*nums[j]) - (nums[i]*nums[i]);
            }
            i++;
            j--;
        }
        return result; 
    }
};


//Better logic:
//Time Complexity: O(nlogn) where n is the size of the input vector nums.
// We sort the vector which takes O(nlogn) time and then iterate through the vector once, performing constant time operations for each element.
//Space Complexity: O(1) as we are using a constant amount of extra space.  

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i] = nums[i]*nums[i];
        }
        sort(nums.begin(), nums.end());

        int i=0;
        int j=n-1;

        while(i<=j){
            if(i==j){
                result += nums[i];
            }
            else{
                result += nums[j] - nums[i];
            }
            i++;
            j--;
        }
        return result; 
    }
};