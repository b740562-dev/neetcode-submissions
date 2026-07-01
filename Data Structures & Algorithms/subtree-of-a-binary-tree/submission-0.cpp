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

// compare two trees are same or not if not compare root tree's left and subroot and root tree's right 
// and subroot
class Solution {
private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr){
            return 1;
        }
        if(p==nullptr || q==nullptr ||p->val!=q->val){
            return 0;
        }
        bool check1=isSameTree(p->left,q->left);
        bool check2=isSameTree(p->right,q->right);
        return check1 && check2;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(isSameTree(root,subRoot)){
            return 1;
        }
        if(root==nullptr || subRoot==nullptr){
            return 0;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
