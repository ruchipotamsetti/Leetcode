
// Solution 1: Brute Force: TC: O(n), SC:O(n)

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
    void reorderList(ListNode* head) {
        
        ListNode* temp = head;
        vector<ListNode*>v;
        while(temp){
            v.push_back(temp);
            temp = temp->next;
        }

        int i=0, j = v.size()-1;
        while(i<j){
            v[i] -> next = v[j];
            i++;
            if(i>=j)
                break;
            v[j] -> next = v[i];
            j--;
        }
        v[j]-> next = nullptr;
    }
};


// Solution 2: Recursion: TC: O(n), SC:O(n)

// Solution 3: Reverse and Merge: TC: O(n), SC:O(1)

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
    void reorderList(ListNode* head) {
        // Find middle
        ListNode *slow = head;
        ListNode *fast = head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        // Separate and Reverse the second half
        ListNode *second = slow -> next;
        slow -> next =  NULL;
        ListNode *prev = NULL;

        while(second){
            ListNode *temp = second -> next;
            second -> next = prev;
            prev = second;
            second = temp;
        }

        // Merge both lists
        ListNode* first = head;
        second = prev;

        while(second){
            ListNode* temp1 = first -> next;
            ListNode* temp2 =  second -> next;

            first -> next = second;
            second -> next = temp1;

            first = temp1;
            second = temp2;
        }
        
    }
};