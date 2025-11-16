// My approach: TC:O(n), SC: O(n)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *temp = head;

        unordered_set<ListNode*>s;

        while(temp){
            if(s.count(temp)){
                return true;
            }
            else{
                s.insert(temp);
            }
            temp = temp->next;
        }

        return false;
    }
};


// Better Approach with Fast and Slow Poniters: TC:O(n), SC: O(1)

// The fast and slow pointer technique works because the relative speed difference between the two pointers guarantees a meeting point if a cycle exists. 
// The slow pointer moves one step at a time, while the fast pointer moves two steps, meaning the distance between them increases by one with each iteration. 
// Once both pointers are in a cycle, the distance between them decreases by one on each iteration, so they are guaranteed to meet at some point within the cycle. 
// This allows for efficient solutions for problems like cycle detection or finding the middle of a linked list. 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while(fast != NULL && fast->next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;

            if(fast == slow)
                return true;
            
        }
        return false;
    }
};
