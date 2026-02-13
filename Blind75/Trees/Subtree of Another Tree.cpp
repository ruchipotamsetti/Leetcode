//Using DFS
// Time Complexity: O(N*M) where N is the number of nodes in the main tree and M is the number of nodes in the subtree
// Space Complexity: O(H) where H is the height of the tree

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot)
            return true;
        if(!root)
            return false;
        if(sameTree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool sameTree(TreeNode* p, TreeNode* q){
        if(!p && !q)
            return true;

        if(p && q && p->val == q->val)
            return sameTree(p->left, q->left) && sameTree(p->right, q->right);
        else
            return false;
    }
};

//Using Serialization(Need to understand the concept of serialization and deserialization of a binary tree)
// Time Complexity: O(N+M) where N is the number of nodes in the main tree and M is the number of nodes in the subtree
// Space Complexity: O(N+M)
