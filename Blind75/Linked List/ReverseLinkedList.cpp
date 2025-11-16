// Brute Force: Storing linked list in array and then traversing in reverse and creating a new Linked list

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
    ListNode* reverseList(ListNode* head) {
        // Brute force:
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *temp = head;

        vector<int>v;

        while(temp != NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        ListNode *prev=NULL;
        for(int i=v.size()-1; i>=0; i--){
            if(i==v.size()-1){
                head->val = v[i];
                prev = head;
            }
            else{
                ListNode *curr = new ListNode(v[i]);
                prev->next = curr;
                prev = curr;
            }
        }
        prev->next =NULL;
        return head;

    }
};

// Recursion: TC:O(n), SC:O(n)

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
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode* newHead = head;
        if (head->next) {
            newHead = reverseList(head->next);
            head->next->next = head;
        }
        head->next = nullptr;

        return newHead;
    }
};

// My approach/Iterative approach:  TC:O(n), SC:O(1)

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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode *prev = head;
        ListNode *curr = head->next;
        prev->next=NULL;
        ListNode *next=NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head=prev;
        return head;
    }
};