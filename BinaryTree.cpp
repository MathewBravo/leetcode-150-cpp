//
// Created by MathewBravo on 2023-08-21.
//

#include "BinaryTree.h"

BinaryTree::TreeNode *BinaryTree::invertTree(BinaryTree::TreeNode *root) {
    if(root == nullptr){
        return nullptr;
    }
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);
    return root;
}

int BinaryTree::maxDepth(BinaryTree::TreeNode *root) {
    if (root == nullptr){
        return 0;
    }
    auto l_res = maxDepth(root->left);
    auto r_res = maxDepth(root->right);
    auto max = l_res > r_res ? l_res : r_res;
    return 1 + max;
}

int BinaryTree::maxDepthQueue(BinaryTree::TreeNode *root) {
    if (root == nullptr) return 0;

    std::queue<TreeNode*> q;
    q.push(root);
    int depth = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        depth++;
    }

    return depth;
}

int BinaryTree::diameterOfBinaryTree(BinaryTree::TreeNode *root) {
    int maxD = 0;
    dfs(root, maxD);
    return maxD;
}

int BinaryTree::dfs(BinaryTree::TreeNode *root, int &maxDiameter) {
    if(root == nullptr) return 0;

    int ld = dfs(root->left, maxDiameter);
    int rd = dfs(root->right, maxDiameter);

    maxDiameter = std::max(maxDiameter, ld + rd);

    return 1 + std::max(ld, rd);
}




