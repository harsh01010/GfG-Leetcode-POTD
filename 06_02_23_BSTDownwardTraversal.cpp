/*
Given a Binary Search Tree with unique node values and a target value. You have to find the node whose data is equal to target and return the sum of all descendant (of target) node's data which are vertically below the target node. Initially, you are at the root node.
Note: If target node is not present in bst then return -1.

Expected Time Complexity: O( n ), n is number of nodes.
Expected Auxiliary Space: O(Height of the tree).
*/

class Solution
{
public:
    bool f(Node *root, Node *&t, int target)
    {
        if (root == NULL)
            return false;
        if (root->data > target)
            f(root->left, t, target);
        else if (root->data < target)
            f(root->right, t, target);

        else
        {
            t = root;
            return true;
        }
    }
    void bakeSum(Node *root, int val, int comp, int &ans)
    {
        if (root == NULL)
            return;
        if (val == comp)
            ans += root->data;
        bakeSum(root->left, val - 1, comp, ans);
        bakeSum(root->right, val + 1, comp, ans);
    }
    long long int verticallyDownBST(Node *root, int target)
    {
        // Code here
        Node *t = NULL;
        int ans = 0;
        bool s = f(root, t, target);
        if (!s)
            return -1;

        bakeSum(t, 0, 0, ans);
        return ans - t->data;
    }
};
