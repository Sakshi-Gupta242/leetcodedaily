class Solution {
public:

    map<int, map<int, multiset<int>>> nodes;

    void dfs(TreeNode* root, int row, int col) {

        if (root == NULL)
            return;

        // current node ko store karo
        nodes[col][row].insert(root->val);

        // left -> row + 1, column - 1
        dfs(root->left, row + 1, col - 1);

        // right -> row + 1, column + 1
        dfs(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;

        // root ki position (0,0)
        dfs(root, 0, 0);

        // columns left to right
        for (auto col : nodes) {

            vector<int> temp;

            // rows top to bottom
            for (auto row : col.second) {

                // same position ki values sorted
                for (int value : row.second) {
                    temp.push_back(value);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};