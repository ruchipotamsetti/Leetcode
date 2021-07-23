//Problem Statement:Given the head of a singly linked list, return true if it is a palindrome.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
//        Approach 1:
//        Runtime: 200 ms, faster than 69.56% of C++ online submissions for Palindrome Linked List.
//        Memory Usage: 113.9 MB, less than 87.56% of C++ online submissions for Palindrome Linked List.
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast && fast->next){ //finding middle node using Floyd's Cycle Detection Algorithm
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *prev = slow;
        ListNode *next;    
        slow = slow->next;
        prev->next = NULL;
        while(slow){ //reversing the second half of the linked list
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        
        slow = prev;
        fast = head;
        while(slow){
            //trasversing from both the ends of the linked list 
            if(fast->val != slow->val)
                return false;
            else{
                fast = fast->next;
                slow = slow->next;
            }
            
        }
        return true;
        
//       (OR)
//          Approach 2:
//          1. Reverse linkedlist and add val to vector simultaneously
//          2. Traverse through the linked list and vector and compare their values
//          3. Return false if value is unequal and true if all values are equal 
//          Runtime: 172 ms, faster than 92.99% of C++ online submissions for Palindrome Linked List.
//          Memory Usage: 120.6 MB, less than 42.73% of C++ online submissions for Palindrome Linked List.
            
//         vector<int>v;
//         ListNode *prev = NULL;
//         ListNode *curr = head;
//         ListNode *next = NULL;
        
//         while(curr != NULL){ 
//             v.push_back(curr->val);
//             next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }
//         head = prev;
        
//         curr = head;
//         int i = 0;
//         while(curr != NULL){
//             if(v[i] != curr->val)
//                 return false;
//             i++;
//             curr = curr->next;
//         }
//         return true;
    }
};
