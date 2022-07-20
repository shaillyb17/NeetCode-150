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

bool isValidBST(TreeNode* root) {
    return validBST(root, LONG_MIN, LONG_MAX);
}
bool validBST(TreeNode* root, long min, long max) {
    if(!root)
        return true;
    if(root->val > min && root->val < max && validBST(root->left, min, root->val) && validBST(root->right, root->val, max))
        return true;
    return false;
}

int main(){
    int n;	cin >> n;
    
    return 0;
}