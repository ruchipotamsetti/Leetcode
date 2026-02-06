// My solution:
// Time Complexity: O(N) where N is the number of nodes in the tree
// Space Complexity: O(H) where H is the height of the tree due to recursion stack
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        int lChild = maxDepth(root->left);
        int rChild = maxDepth(root->right);

        return max(lChild, rChild) + 1;
    }
};

// Alternate solution using BFS:
// Time Complexity: O(N) where N is the number of nodes in the tree
// Space Complexity: O(W) where W is the maximum width of the tree
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        queue<TreeNode*>q;
        q.push(root);
        int depth = 0;

        while(!q.empty()){
            int levelSize = q.size();
            for(int i=0; i<levelSize; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            depth++;
        }
        return depth;
    }
};

// Another alternate solution using DFS with stack:(NEED TO REVIEW)
// Time Complexity: O(N) where N is the number of nodes in the tree
// Space Complexity: O(H) where H is the height of the tree due to stack space
class Solution {
public: 
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});
        int maxDepth = 0;

        while(!s.empty()){
            auto [node, depth] = s.top();
            s.pop();
            if(node){
                maxDepth = max(maxDepth, depth);
                s.push({node->left, depth + 1});
                s.push({node->right, depth + 1});
            }
        }
        return maxDepth;
    }
};