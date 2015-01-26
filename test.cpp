#include <iostream>
#include <stack>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *prev;
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, INT_MIN-1, INT_MAX+1);
        
    }
    bool isValidBST(TreeNode *root, long long min, long long max) {
        if(root == NULL)
            return 1;
        // speicail case to handle overflow
        if(root->val == INT_MAX && root->right!=NULL)
            return 0;
        if(root->val == INT_MIN && root->left!=NULL)
            return 0;
        return (root->val > min && root->val <max) &&
            isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
};

int main()
{
    TreeNode a1(0);

    //a4.left = &a6;
    //a5.right = &a7;
    Solution solution;
    solution.isValidBST(&a1);
}
