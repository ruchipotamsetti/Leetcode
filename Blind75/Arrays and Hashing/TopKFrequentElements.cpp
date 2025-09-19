// Solution using Vector:

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>count;
        vector<int>result;
        for(auto val: nums){
            count[val]++;
        }

        vector<pair<int, int>>arr;
        for(auto e: count){
            arr.push_back({e.second, e.first});
        }
        sort(arr.rbegin(), arr.rend());

        for(int i=0; i<k; i++){
            result.push_back(arr[i].second);
        }

        return result;
    }
};

// Solution using Max heap:

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>count;
        vector<int>result;
        for(auto val: nums){
            count[val]++;
        }

        priority_queue<pair<int, int>>maxHeap;
        for(auto e: count){
            maxHeap.push({e.second, e.first});
        }

        while(!maxHeap.empty() && k>0){
            pair<int, int> top = maxHeap.top();
            result.push_back(top.second);
            maxHeap.pop();
            k--;
        }

        return result;
    }
};


// Solution with Min Heap

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>count;
        vector<int>result;
        for(auto val: nums){
            count[val]++;
        }

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>>minHeap;
        for(auto e: count){
            minHeap.push({e.second, e.first});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        while(!minHeap.empty() && k>0){
            pair<int, int> top = minHeap.top();
            result.push_back(top.second);
            minHeap.pop();
            k--;
        }

        return result;
    }
};