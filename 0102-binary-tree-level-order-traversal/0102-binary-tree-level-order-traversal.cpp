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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        //agar tree empty hai
        if (root == nullptr)
        return ans;

        queue<TreeNode*>q;

        //root ko queue me daalo
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int>level;

            //current level ke saare node process karo
            for(int i = 0;i<size;i++){
                TreeNode*node = q.front();
                q.pop();

                level.push_back(node->val);
                //left child
                if(node->left!= nullptr)
                q.push(node->left);

                //right child
                if(node->right!= nullptr)
                q.push(node->right);
            }
            //current level ko ans me daalo
            ans.push_back(level);
        }
        return ans;       
    }
};