#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int countGood(TreeNode* root, int base) {
    if(!root)
        return 0;
    if(root->val < base)
        return countGood(root->left, base) + countGood(root->right, base);
    return 1 + countGood(root->left, root->val) + countGood(root->right, root->val);
}

int goodNodes(TreeNode* root) {
    if(!root)
        return 0;
    return 1 + countGood(root->left, root->val) + countGood(root->right, root->val);
}

int main(){
    int n;	cin >> n;
    
    return 0;
}