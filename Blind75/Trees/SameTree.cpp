// My approach:
// Time Complexity: O(N) where N is the number of nodes in the tree
// Space Complexity: O(W) where W is the maximum width of the tree
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;

        if(p==NULL || q==NULL)
            return false;

        queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty()){

            int levelSize1=q1.size();
            int levelSize2=q2.size();

            if(levelSize1!=levelSize2)
                return false;

            for(int i=0; i<levelSize1; i++){
                TreeNode* curr1=q1.front();
                TreeNode* curr2=q2.front();
                q1.pop();
                q2.pop();
                
                if(!curr1 && !curr2) continue;
                if(!curr1 || !curr2) return false;
                if(curr1->val !=curr2->val) return false;

                q1.push(curr1->left);
                q1.push(curr1->right);

                q2.push(curr2->left);
                q2.push(curr2->right);
            }
        }
        return true;
    }
};

// DFS using recursion
// Time Complexity: O(N) where N is the number of nodes in the tree
// Space Complexity: O(H) where H is the height of the tree

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(p && q && p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else{
            return false;
        }
        
    }
};

// DFS using stack(Need to revisit this approach)
// Time Complexity: O(N) where N is the number of nodes in the tree
// Space Complexity: O(H) where H is the height of the tree
class Solution {
public: 
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        s1.push(p);
        s2.push(q);

        while(!s1.empty() && !s2.empty()){
            TreeNode* curr1=s1.top();
            TreeNode* curr2=s2.top();
            s1.pop();
            s2.pop();

            if(!curr1 && !curr2) continue;
            if(!curr1 || !curr2) return false;
            if(curr1->val !=curr2->val) return false;

            s1.push(curr1->left);
            s1.push(curr1->right);

            s2.push(curr2->left);
            s2.push(curr2->right);
        }
        return true;
    }
};