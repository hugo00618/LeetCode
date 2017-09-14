//
//  _22.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-14.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class _22 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result = {};
        
        generateParenthesisRecur(result, "", n, 0);
        
        return result;
    }
    
    void generateParenthesisRecur(vector<string> &vec, string s, int left, int right) {
        if (left == 0) {
            for (int i = 0; i < right; i++) {
                s += ")";
            }
            vec.push_back(s);
            return;
        }
        
        if (left > 0) {
            generateParenthesisRecur(vec, s + "(", left - 1, right + 1);
        }
        if (right > 0) {
            generateParenthesisRecur(vec, s + ")", left, right - 1);
        }
    }
};



