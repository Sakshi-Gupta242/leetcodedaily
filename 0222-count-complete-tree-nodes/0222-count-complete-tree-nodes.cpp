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
public:
   int heightleft (TreeNode*root){
    int h=0;

    while(root){
        h++;
        root = root->left;
    }
    return h;
   }
   int heightright (TreeNode*root){
    int h=0;

    while(root){
        h++;
        root = root->right;
    }
    return h;
   }
    int countNodes(TreeNode* root) {
        if(root == NULL)
        return 0;

        
        int left = heightleft(root);
        int right = heightright(root);
        if(left== right){
         return (1<< left)-1;     
        }
        return 1 +countNodes(root->left)+countNodes(root->right);    
    }
};