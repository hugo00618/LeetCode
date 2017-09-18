//
//  _36.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-18.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class _36 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<char> subBox1, subBox2, subBox3;
        vector<vector<char>> columns(9);
        for (int i = 0; i < board.size(); i++) {
            vector<char> row = board[i];
            
            // check row duplicates
            if (!isLineValid(row)) {
                return false;
            }
            
            for (int j = 0 ; j < 9; j++) {
                char entry = row[j];
                
                // push to subBox
                if (j <= 2) {
                    subBox1.push_back(entry);
                } else if (j <= 5) {
                    subBox2.push_back(entry);
                } else {
                    subBox3.push_back(entry);
                }
                
                // push to columns
                columns[j].push_back(entry);
            }
            
            // check boxes if row % 3 == 0
            if ((i + 1) % 3 == 0) {
                if (!isLineValid(subBox1) || !isLineValid(subBox2) || !isLineValid(subBox3)) {
                    return false;
                }
                
                subBox1 = {};
                subBox2 = {};
                subBox3 = {};
            }
        }
        
        for (vector<char> column: columns) {
            if (!isLineValid(column)) {
                return false;
            }
        }
        
        return true;
    }
    
    bool isLineValid(vector<char> line) {
        sort(line.begin(), line.end());
        for (int i = 1; i < line.size(); i++) {
            if (line[i - 1] == line[i] && line[i] != '.') {
                return false;
            }
        }
        
        return true;
    }
};
