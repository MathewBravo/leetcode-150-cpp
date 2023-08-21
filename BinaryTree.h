//
// Created by MathewBravo on 2023-08-21.
//

#ifndef NEEDCODE_BINARYTREE_H
#define NEEDCODE_BINARYTREE_H


#include <queue>


class BinaryTree {
    struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    TreeNode* invertTree(TreeNode* root);
    int maxDepth(TreeNode* root);
    int maxDepthQueue(TreeNode* root);
    int diameterOfBinaryTree(TreeNode* root);
    int dfs(TreeNode* root, int &maxDiameter);



};


#endif //NEEDCODE_BINARYTREE_H
