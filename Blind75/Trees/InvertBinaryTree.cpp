// My code:
// Bottom up approach
// Time Complexity: O(N)
// Space Complexity: O(H) where H is the height of the tree due to recursion stack
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;

        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);

        return root;
    }
};

//BFS Approach
// Time Complexity: O(N)    
// Space Complexity: O(W) where W is the maximum width of the tree
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            swap(node->left, node->right);
            if (node->left) queue.push(node->left);
            if (node->right) queue.push(node->right);
        }
        return root;
    }
};

// DFS Approach (Top down approach)
// Time Complexity: O(N)    
// Space Complexity: O(H) where H is the height of the tree due to recursion stack
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

// DFS Approach (Using stack)
// Time Complexity: O(N)
// Space Complexity: O(H) where H is the height of the tree due to stack space
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        stack<TreeNode*> stack;
        stack.push(root);
        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();
            swap(node->left, node->right);
            if (node->left) stack.push(node->left);
            if (node->right) stack.push(node->right);
        }
        return root;
    }
};