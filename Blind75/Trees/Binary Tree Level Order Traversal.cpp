//My code:
//Time complexity: O(n) where n is the number of nodes in the tree
//Space complexity: O(n) where n is the number of nodes in the tree

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>nodes;
        if(!root)
            return nodes;
        q.push(root);
        while(!q.empty()){
            int levelSize = q.size();
            vector<int>v;
            for(int i=0; i<levelSize; i++){
                TreeNode* curr = q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            nodes.push_back(v);
        }

        return nodes;
    }
};

//Better written code:
//Time complexity: O(n) where n is the number of nodes in the tree  
//Space complexity: O(n) where n is the number of nodes in the tree
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> level;
            int size = q.size();

            for (int i = q.size(); i > 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                if (node) {
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if (!level.empty()) {
                res.push_back(level);
            }
        }
        return res;
    }
};

//Using DFS:
//Time complexity: O(n) where n is the number of nodes in the tree  
//Space complexity: O(n) where n is the number of nodes in the tree

class Solution {
public:
    vector<vector<int>>nodes;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return nodes;

        dfs(root, 0);
        return nodes;
    }

    void dfs(TreeNode* root, int depth){
            if(!root)
                return;

            if(nodes.size() == depth)
                nodes.push_back(vector<int>());

            nodes[depth].push_back(root->val);
            dfs(root->left, depth+1);
            dfs(root->right, depth+1);
    }


};