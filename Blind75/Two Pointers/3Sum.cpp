// Brute Force: TC: O(n^3), SC: O(m), Where m is the number of triplets and n is the length of the given array.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>s;
        sort(nums.begin(), nums.end()); //If you insert unordered vectors into a set<vector<int>>, the set will treat them as different elements, because sets compare lexicographically and {−1,0,1} ≠ {0,−1,1}. Therefore, we order the array first.
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        s.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        vector<vector<int>>result(s.begin(), s.end());
        return result;

    }
};

// Solution 1: TC: O(n^2), SC: O(n^2)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        set<vector<int>>r;
        for(int i=0; i<n-2; i++){
            if(nums[i]>0)
                break;
            if(i>0 && nums[i] == nums[i-1])
                continue;
            int target = -nums[i];
            int j= i+1, k=n-1;
            while(j<k){
                if(nums[j] + nums[k] == target){
                    r.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(nums[j] + nums[k] > target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        vector<vector<int>>result(r.begin(), r.end());
        return result;
    }
};

// Optimized space Solution 2: TC: O(n^2), but faster because there is no inserting into set which costs log(m) where m is the number of triplets stored.
// O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        vector<vector<int>>r;
        for(int i=0; i<n-2; i++){
            if(nums[i]>0)
                break;
            if(i>0 && nums[i] == nums[i-1])
                continue;
            int target = -nums[i];
            int j= i+1, k=n-1;
            while(j<k){
                if(nums[j] + nums[k] == target){
                    r.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]){
                        j++;
                    }
                }
                else if(nums[j] + nums[k] > target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return r;
    }
};

