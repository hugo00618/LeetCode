//
//  _17.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-13.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class _17 {
public:
    vector<vector<char>> letters = {{}, {}, {'a','b','c'}, {'d','e','f'}, {'g','h','i'},
        {'j','k','l'}, {'m','n','o'}, {'p','q','r','s'}, {'t', 'u','v'}, {'w','x','y','z'}};
    
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return {};
        }
        
        vector<string> result = {""};
        
        for (char c: digits) {
            int i = ((int) c) - 48;
            
            vector<string> newResult = {};
            for (string s: result) {
                for (char letter: letters[i]) {
                    newResult.push_back(s + letter);
                }
            }
            result = newResult;
        }
        
        return result;
    }
};
