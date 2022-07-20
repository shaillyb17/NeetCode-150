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

int diaBT(TreeNode* root, int& res) {
    if(!root)    
        return 0;
    int l = diaBT(root->left, res);
    int r = diaBT(root->right, res);
    int temp = 1 + max(l,r);
    int ans = max(temp, 1 + l + r);
    res = max(res, ans);
    return temp;
}

int diameterOfBinaryTree(TreeNode* root) {
    if(!root)
        return 0;
    int res = INT_MIN;
    diaBT(root, res);
    return res - 1;
}

int main(){
    int n;	cin >> n;
    
    return 0;
}