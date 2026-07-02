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
    TreeNode* build(vector<int>& preorder, int prestart,int preend,vector<int>& inorder,int instart,int inend,map<int,int>& mpp){
        if(instart>inend || prestart>preend){
            return nullptr;
        }
        // indices are written based on we find prestart index inorder array and call inorder in two halfs 
        // for that two halfs we will write indexes of preorder !!!
        TreeNode* curroot=new TreeNode(preorder[prestart]);
        int currindex=mpp[preorder[prestart]];
        // connect the new nodes with curroot
        curroot->left=build(preorder,prestart+1,prestart+currindex-instart,inorder,instart,currindex-1,mpp);
        curroot->right=build(preorder,prestart+currindex-instart+1,preend,inorder,currindex+1,inend,mpp);
        return curroot;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // preorder stores the root as its first element 
       map<int,int> mpp;
       int n=inorder.size();
       for(int i=0;i<n;i++){
            mpp[inorder[i]]=i;
       }
       return build(preorder,0,n-1,inorder,0,n-1,mpp);
    }
};
