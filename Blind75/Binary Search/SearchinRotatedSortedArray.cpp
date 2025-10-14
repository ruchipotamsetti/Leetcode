// Brute Force: TC: O(n), SC:O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
};

// Binary Search: TC: O(logn), SC:O(1)


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        int pivot = l;

        int result = binarySearch(nums, target, 0, pivot - 1);
        if (result != -1) {
            return result;
        }

        return binarySearch(nums, target, pivot, nums.size() - 1);
    }

    int binarySearch(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

// Binary Search-two pass: TC: O(logn), SC:O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        int pivot = l;
        l = 0;
        r = nums.size() - 1;

        if (target >= nums[pivot] && target <= nums[r]) {
            l = pivot;
        } else {
            r = pivot - 1;
        }

        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return -1;
    }
};


// Binary Search-one pass: TC: O(logn), SC:O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int l=0, r=n-1, m;

        while(l<=r){
            m = (r-l)/2 + l;
            if(target == nums[m]){
                return m;
            }
            
           
            if(nums[m]>=nums[l]){
                if(target<nums[l] || target>nums[m]){
                    l=m+1;
                }
                else
                    r = m-1;
            }
            else{
                if(target>nums[r] || target<nums[m])
                    r = m-1;
                else
                    l=m+1;
            }
            
        }
        return -1;
    }
};