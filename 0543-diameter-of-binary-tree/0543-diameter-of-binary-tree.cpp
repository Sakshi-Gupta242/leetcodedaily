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
    int height(TreeNode*root,int& diameter) {
       if(root == NULL)
       return 0;
       //left subtree ki height
       int lh = height(root ->left,diameter);
       //right subtree ki height
       int rh = height(root-> right,diameter);
       //current node se banne vaala diameter
       diameter = max(diameter,lh+rh);
       //current subtree ki height
       return 1+ max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};