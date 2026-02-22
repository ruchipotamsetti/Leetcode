// Brute Force:(Need to review)


// Using DFS:
//Time Complexity: O(n) where n is the number of nodes in the tree
//Space Complexity: O(n) in the worst case when the tree is completely unbalanced,
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }

    bool valid(TreeNode* node, long left, long right){
        if(!node)
            return true;

        if(!(node->val>left && node->val<right))
            return false;

        return valid(node->left,left,node->val) && valid(node->right, node->val, right);
    }
};

//Using BFS:
//Time Complexity: O(n) where n is the number of nodes in the tree
//Space Complexity: O(n) in the worst case when the tree is completely unbalanced,
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        queue<tuple<TreeNode*, long, long>>q;
        q.push(make_tuple(root, LONG_MIN, LONG_MAX));

        while(!q.empty()){
            auto [node, left, right] = q.front();
            q.pop();

            if(!(node->val>left && node->val<right))
                return false;

            if(node->left){
                q.push(make_tuple(node->left, left, node->val));
            }

            if(node->right){
                q.push(make_tuple(node->right, node->val, right));
            }
        }
        return true;
    }
};
