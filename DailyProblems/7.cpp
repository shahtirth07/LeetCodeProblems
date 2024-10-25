class Solution
{
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        // Both nodes are null
        if (root1 == nullptr && root2 == nullptr)
        {
            return true;
        }

        // One of the nodes is null
        if (root1 == nullptr || root2 == nullptr)
        {
            return false;
        }

        // Check if the current nodes are equal
        if (root1->val != root2->val)
        {
            return false;
        }

        // Check the two scenarios: without flipping or with flipping
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};
