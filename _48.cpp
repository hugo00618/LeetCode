//
//  _48.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-21.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class _48 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < matrix.size() - 1; i++) {
            for (int j = i; j < matrix.size() - 1 - i; j++) {
                swap(matrix[i][j], matrix[j][n-1-i]);
                swap(matrix[i][j], matrix[n-1-i][n-1-j]);
                swap(matrix[i][j], matrix[n-1-j][i]);
            }
        }
    }
};
