//
//  PalindromeCounter.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-24.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>

using namespace std;

class PalindromeCounter {
public:
    bool isPalindrome(string& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
    
//    int countPalindrome(string s) {
//        int res = 0;
//        for (int i = 0; i < s.length(); i++) {
////            countPalindrome(res, i)
//        }
//    }
    
    void countPalindrome(int& res, int i, string temp, string s) {
        if (temp.size() >= s.size() / 2) {
            return;
        }
        if (isPalindrome(temp)) {
            res++;
        }
        temp.push_back(s[i]);
        countPalindrome(res, i + 1, temp, s);
        temp.pop_back();
    }
    
};
