//
//  _101.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-11-20.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <stdio.h>

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class _101 {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        } else {
            return isIdentical(root->left, root->right);
        }
    }
    
    bool isIdentical(TreeNode *node1, TreeNode *node2) {
        if (node1 == NULL && node2 == NULL) {
            return true;
        } else if (node1 == NULL || node2 == NULL) {
            return false;
        } else if (node1->val == node2->val) {
            return isIdentical(node1->left, node2->right) &&
            isIdentical(node1->right, node2->left);
        } else {
            return false;
        }
    }
};
