//
//  _236.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-11-29.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//
//  This was an Amazon tech interview question

#include <iostream>
#include "TreeNode.cpp"

using namespace std;

class _236 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if root is null or root is one of the targets, return root
        if (root == NULL || root == p || root == q) {
            return root;
        } else {
            TreeNode *leftLCA = lowestCommonAncestor(root->left, p, q);
            TreeNode *rightLCA = lowestCommonAncestor(root->right, p, q);
            
            if (leftLCA == NULL) { // if left has nothing
                return rightLCA; // return right LCA
            } else if (rightLCA == NULL) { // if right has nothing
                return leftLCA; // return left LCA
            } else { // if one on left and one on right
                return root; // return current root
            }
        }
    }
};
