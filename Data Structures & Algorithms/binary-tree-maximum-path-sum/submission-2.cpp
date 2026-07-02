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
    int height(TreeNode* root,int& maxi){
        if(root==nullptr){
            return 0;
        }
        // for a given node if taking it's left or right is worth or not can be checked as :
        int left=max(0,height(root->left,maxi));
        int right=max(0,height(root->right,maxi));
        maxi=max(maxi,root->val+left+right);
        // we are returning currmax because upar wala node can either choose left or right path
        // can't choose both simultaneously !!!
        return root->val+max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        // max path same can be written as we find diameter of binary tree in the maxdepth finding q'
        int maxi=INT_MIN;
        height(root,maxi);
        return maxi; 
    }
};
