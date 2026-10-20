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
 // preorder root->left->right
class Solution {
public:
    void preorder(TreeNode*node,vector<int>& ans){
        //if node doesnot exist
        if(node == nullptr)
        return;
    
    //Root ko ans me daalo
    ans.push_back(node->val);
    //left subtree par jao
    preorder(node->left,ans);
    //right subtree par jao
    preorder(node->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        //ans store karne ke liye
        vector<int>ans;

        //root se traversal start
        preorder(root,ans);

        return ans;      
    }
};