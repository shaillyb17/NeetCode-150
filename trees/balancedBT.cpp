#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int calcHeight(TreeNode* root) {
    if(!root)
        return 0;
    return max(calcHeight(root->left), calcHeight(root->right)) + 1;
}
bool isBalanced(TreeNode* root) {
    if(!root)
        return true;
    if(abs(calcHeight(root->left) - calcHeight(root->right)) > 1 || !isBalanced(root->left) || !isBalanced(root->right))
        return false;
    return true;
}

int main(){
    int n;	cin >> n;
    
    return 0;
}