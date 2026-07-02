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

class Codec {
public:

    // Encodes a tree to a single string.
    // applying BFS to traverse the nodes level wise---implementing using queue !!!!
    string serialize(TreeNode* root) {

        string s="";

        if(root==nullptr){
            return s;
        }

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){

            TreeNode* curr=q.front();
            if(curr==nullptr){
                s+="#,";
            }

            else{
                // for int to string conversion use curr->val !!!!
                // we have to use a "," which will act as a delimiter !!!
                s+=to_string(curr->val)+",";
            }

            q.pop();
            if(curr){
                q.push(curr->left);
                q.push(curr->right);
            }

        }

        return s;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n=data.size();
        if(n==0){
            return nullptr;
        }

        // serialise returns string as "1,2,3,#,#,4,5,#,#,#,#"

        // getline will split this and stores our nodes in vector<string>
        // can't write vector<int> because token we get from data will necessary be string !!!
        vector<string> nodes;
        stringstream ss(data);
        string token;

        while (getline(ss, token, ',')) {
            if(!token.empty()){
                nodes.push_back(token);
            }
        }


        TreeNode* root=new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i=1;
        
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(nodes[i]!="#"){
                // need to make new nodes for curr->left and curr->right!!!!
                // obviously old nodes don't exist !!!!
                curr->left=new TreeNode(stoi(nodes[i]));
                q.push(curr->left);
            }
            i++;
            if(nodes[i]!="#"){
                curr->right=new TreeNode(stoi(nodes[i]));
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};
