//
//  _5.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-07-18.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class _5 {
public:
    string longestPalindrome(string s) {
        if (s == "") {
            return "";
        }
        
        string longestString = s.substr(0,1);
        for (int i = 0; i < s.length() - 1; i++) {
            vector<int> bounds;
            if (s[i] != s[i+1]) { // aba
                bounds = longestPalindromeRecur(s, i, i);
            } else { // abba
                bounds = longestPalindromeRecur(s, i, i + 1);
            }
            
            int left = bounds[0], right = bounds[1];
            if (right - left + 1 > longestString.size()) {
                longestString = s.substr(left, right - left + 1);
            }
        }
        
        return longestString;
    }
    
    vector<int> longestPalindromeRecur(string s, int left, int right) {
        if (left - 1 < 0 || right + 1 >= s.size()) { // out of bound
            return {left, right};
        } else if (s[left - 1] == s[right + 1]) { // expand 1 char
            return longestPalindromeRecur(s, left - 1, right + 1);
        } else { // current char don't match
            return {left, right};
        }
    }

};
