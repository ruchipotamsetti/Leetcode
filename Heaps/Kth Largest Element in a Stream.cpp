//my approach
//time complexity: O(mlogn) for sorting the array every time we add a new element, where m is the number of times we call the add function and n is the number of elements in the array
//space complexity: O(n) for storing the elements in the array
class KthLargest {
public:
    int kth;
    vector<int>scores;
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        scores = nums;
    }
    
    int add(int val) {
        scores.push_back(val);
        sort(scores.begin(), scores.end(), std::greater<int>());
        return scores[kth-1];
    }
};


//my approach using max heap:
//time complexity: O(nlogn) for building the max heap every time we add a new element
//space complexity: O(n) for storing the elements in the array and the max heap
//why it did not work:
//A common mistake is using a max-heap to find the k-th largest element. 
// While it seems intuitive to keep the largest elements at the top, 
// a max-heap would require storing all elements and repeatedly extracting 
// the maximum k times for each query.
class KthLargest {
public:
    int kth;
    vector<int>scores;
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        scores = nums;
    }
    
    int add(int val) {
        scores.push_back(val);
        priority_queue<int>pq;
        for(auto i:scores){
            pq.push(i);
        }
        int i=0;
        while(i<kth-1){
            pq.pop();
            i++;
        }
        return pq.top();
    }
};

//optimal solution using min heap:
//time complexity: O(mlogk) for adding a new element to the min heap and maintaining the size of the heap to k, where m is the number of times we call the add function and k is the size of the heap. In the worst case, when m is large and k is small, this can be O(m log k). In the best case, when m is small and k is large, this can be O(log k) for each add operation.
//space complexity: O(k) for storing the k largest elements in the min heap
class KthLargest {
public:
    int kth;
    priority_queue<int, vector<int>, greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        kth=k;
        for(auto num:nums){
            pq.push(num);
            if(pq.size()>kth)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>kth)
            pq.pop();
        return pq.top();
    }
};




