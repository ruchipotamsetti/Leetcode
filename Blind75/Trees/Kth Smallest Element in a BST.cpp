//BruteForce(My solution):
//Time Complexity: O(nlogn) + O(n) = O(nlogn)
//Space Complexity: O(n) for storing the values of the nodes in the vector

class Solution {
public:
    vector<int>v;
    int kthSmallest(TreeNode* root, int k) {

        traverse(root);
        sort(v.begin(), v.end());
        return v[k-1];
    }

    void traverse(TreeNode* root){
        if(!root)
            return;

        v.push_back(root->val);
        if(root->left)
            traverse(root->left);
        if(root->right)
            traverse(root->right);
        
        return;
    }
};

//Optimal Solution(Using Inorder Traversal):
//Time Complexity: O(n) where n is the number of nodes in the tree
//Space Complexity: O(h) where h is the height of the tree, which is the space used by the recursion stack. In the worst case, when the tree is completely unbalanced, the height can be equal to n, resulting in O(n) space complexity.
class Solution {
public:
    vector<int>v;
    int kthSmallest(TreeNode* root, int k) {
        traverse(root);
        return v[k-1];
    }

    void traverse(TreeNode* root){
        if(!root)
            return;

        if(root->left)
            traverse(root->left);
        v.push_back(root->val);
        if(root->right)
            traverse(root->right);
        
        return;
    }
};

//Optimal Solution(Using Iterative Inorder Traversal):
//So instead of storing all values, we can:
//Traverse the tree in inorder,
//Count nodes as we visit them,
//Stop as soon as we visit the k-th smallest node.
//Time Complexity: O(n) in the worst case when k is equal to n, meaning we have to traverse the entire tree. In the best case, when k is 1, we only visit the leftmost node, resulting in O(1) time complexity.
//Space Complexity: O(h) where h is the height of the tree, which is the space used by the stack. In the worst case, when the tree is completely unbalanced, the height can be equal to n, resulting in O(n) space complexity.
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>v(2);
        v[0]=k;
        traverse(root, v);
        return v[1];
    }

    void traverse(TreeNode* root, vector<int> &v){
        if(!root)
            return;

        if(root->left)
            traverse(root->left, v);

        v[0]--;
        if(v[0]==0){
            v[1] = root->val;
            return;
        }
        
        if(root->right)
            traverse(root->right, v);
        
        return;
    }
};

//Morris Traversal Solution:(Need to review this solution)
//Time Complexity: O(n) in the worst case when k is equal to n, meaning we have to traverse the entire tree. In the best case, when k is 1, we only visit the leftmost node, resulting in O(1) time complexity.
//Space Complexity: O(1) as we are not using any additional data structures to store the nodes or values. The Morris Traversal modifies the tree structure temporarily to achieve the inorder traversal without recursion or a stack, thus using constant space.