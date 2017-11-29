//
//  TreeNode.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-11-29.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}    
};
