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
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        else
        {
            int left = findHeight(root->left);
            int right = findHeight(root->right);
            if (abs(left - right) <= 1)
            {
                bool isLeftBalanced = isBalanced(root->left);
                bool isRightBalanced = isBalanced(root->right);
                return isLeftBalanced && isRightBalanced;
            }
            else
            {
                return false;
            }
        }
    }

    int findHeight(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = 1 + findHeight(root->left);
        int right = 1 + findHeight(root->right);
        return max(left, right);
    }
};