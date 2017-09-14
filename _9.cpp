//
//  _9.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-07-13.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>

class _9 {
public:
    bool isPalindrome(int x) {
        if (x != 0 && x%10 == 0) {
            return false;
        } else {
            return isPalindromeRecur(x, 0);
        }
    }
    
    bool isPalindromeRecur(int x, int y) {
        if (x < y) {
            return false;
        } else if (x == y || x/10 == y) {
            return true;
        } else {
            int newX = x / 10;
            int newY = y * 10 + x % 10;
            
            return isPalindromeRecur(newX, newY);
        }
    }
};
