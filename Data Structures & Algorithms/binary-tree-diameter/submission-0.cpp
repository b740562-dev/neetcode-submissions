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

// a tweak in height dfs code returns the dia of binary tree---
class Solution {
private:
    int height(TreeNode* root,int& dia){
        if(root==nullptr){
            return 0;
        }
        int left=height(root->left,dia);
        int right=height(root->right,dia);
        // for every node we check it's left height and it's right height---sum of them provides a 
        // path and we try to maximize dia variable 
        dia=max(dia,left+right);
        return 1+max(left,right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // no. of edges=no. of nodes-1 !!!
        // use height function and call diameter in that 
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
};
