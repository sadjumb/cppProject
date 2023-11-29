#include <iostream>
#include <vector>

/**
 * Definition for a binary tree node. */

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void Inorder(TreeNode* root, std::vector<int>& res)
    {
        if (root == nullptr) return;

        Inorder(root->left, res);

        int num = root->val;
        res.push_back(num);

        Inorder(root->right, res);
    }

    std::vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> res;
        Inorder(root, res);
        return res;
    }
};

int main(int argc, char* argv[])
{
    TreeNode* start = new TreeNode(1);
    start->right = new TreeNode(2);
    start->right->right = new TreeNode(3);
    Solution a;
    for (const auto i : a.inorderTraversal(start))
        std::cout << i << ' ';
    return 0;
}
