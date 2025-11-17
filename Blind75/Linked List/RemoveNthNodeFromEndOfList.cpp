// Solution 1:My approach(also Brute Force): Single pass but with space, TC: O(n), SC O(n)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*>nodes;
        ListNode* temp = head;
        while(temp){
            nodes.push_back(temp);
            temp = temp->next;
        }

        int total = nodes.size();
        int remove = total - n + 1;
        int index = remove - 1;

        if(total == 1){
            head = nullptr;
        }
        else{
            ListNode *next = nodes[index] -> next;
            if(index == 0){
                head = next;
            }
            else{
                nodes[index - 1] -> next = next;
            }    
        }
        ListNode *delNode = nodes[index];
        delete delNode;
        
        return head;
    }
};

// Solution 1:Simplified version of My approach(it is also Brute Force): TC: O(n), SC O(n)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        ListNode* cur = head;
        while (cur != nullptr) {
            nodes.push_back(cur);
            cur = cur->next;
        }

        int removeIndex = nodes.size() - n;
        if (removeIndex == 0) {
            return head->next;
        }

        nodes[removeIndex - 1]->next = nodes[removeIndex]->next;
        return head;
    }
};

// Solution 2: Iteration(Two Pass): TC: O(n), SC O(1)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int N=0;
        ListNode *temp = head;
        while(temp){
            temp = temp->next;
            N++;
        }
        int removeIndex = N-n;

        if(removeIndex == 0)
            return head -> next;

        temp = head;
        for(int i=0; i<removeIndex-1; i++){
            temp = temp -> next;
        }

        temp -> next = temp-> next -> next;
        return head;
    }
};

// Solution 3: Recursion: : TC: O(n), SC O(n)



// Solution 4: (Best)Using Two Pointers: TC: O(n), SC O(1)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy;
        ListNode *left = &dummy;
        left -> next = head;
        ListNode *right = head;

        while(n>0){
            right =  right -> next;
            n--;
        }

        while(right){
            left = left -> next;
            right = right -> next;
        }

        left->next = left ->next->next;
        
        return dummy.next;
    }
};