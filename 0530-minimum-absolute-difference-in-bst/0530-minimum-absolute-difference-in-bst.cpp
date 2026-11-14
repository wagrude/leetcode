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
    vector<int> values;

    int getMinimumDifference(TreeNode* root) {
        values.clear();
        inorder(root);

        int minDiff = INT_MAX;

        for (int i = 1; i < values.size(); i++) {
            minDiff = min(minDiff, values[i] - values[i - 1]);
        }

        return minDiff;
    }

    void inorder(TreeNode* root) {
        if (root == nullptr) return;

        inorder(root->left);
        values.push_back(root->val);
        inorder(root->right);
    }
};