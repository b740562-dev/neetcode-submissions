/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
// keep a low and high pointer to ensure a node is not only locally compared but it is compared globally !!!!
    bool dfs(TreeNode* root,long long low,long long high){
        // pre order traversal is being done here 
        if(root==nullptr){
            return 1;
        }
        if(root->val<=low || root->val>=high){
            return 0;
        }
        return dfs(root->left,low,root->val) && dfs(root->right,root->val,high);
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root,INT_MIN,INT_MAX);
    }
};
