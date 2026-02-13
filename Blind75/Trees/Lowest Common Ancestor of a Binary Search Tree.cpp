//My solution:
//Time complexity: O(h) where h is the height of the tree
//Space complexity: O(h) where h is the height of the tree
//Space complexity in terms of nodes is O(n) in the worst case when the tree is skewed

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val==root->val)
            return p;
        if(q->val==root->val)
            return q;   
        if((p->val < root->val && q->val > root-> val) || (q->val < root->val && p->val > root-> val))
            return root;

        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }
};

//Better written code:
//Time complexity: O(h) where h is the height of the tree
//Space complexity: O(h) where h is the height of the tree
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(max(p->val, q->val)<root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(min(p->val, q->val)>root->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};

//Iterative solution:
//Time complexity: O(h) where h is the height of the tree
//Space complexity: O(1)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;

        while(curr){
            if(max(p->val, q->val)<curr->val)
                curr = curr->left;
            else if(min(p->val, q->val)>curr->val)
                curr = curr->right;
            else
                return curr;
        }

        return nullptr;
    }
};