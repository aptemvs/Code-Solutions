#include <iostream>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    {};

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {};

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
    {};
};

class Solution
{
public:
    static void getSubTree(TreeNode* root, std::vector<int>& vec)
    {

        if (root != nullptr)
        {
            getSubTree(root->left, vec);
            vec.push_back(root->val);
            getSubTree(root->right, vec);
        }
    }

    static std::vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> storage;

        getSubTree(root, storage);

        return storage;
    }
};