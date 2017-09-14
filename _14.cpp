//
//  _12.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-08-25.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class _14 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        } else if (strs.size() == 1) {
            return strs[0];
        } else if (strs.size() == 2) {
            return longestCommonPrefix(strs[0], strs[1]);
        } else {
            int mid = strs.size() / 2;
            
            vector<string> left(strs.begin(), strs.begin() + mid);
            vector<string> right(strs.begin() + mid, strs.end());
            
            string leftPrefix = longestCommonPrefix(left);
            string rightPrefix = longestCommonPrefix(right);
            
            return longestCommonPrefix(leftPrefix, rightPrefix);
        }
    }
private:
    string longestCommonPrefix(string& s1, string& s2) {
        string commonPrefix = "";
        for (int i = 0; i < s1.length() && i < s2.length(); i++) {
            if (s1[i] == s2[i]) {
                commonPrefix += s1[i];
            } else {
                break;
            }
        }
        
        return commonPrefix;
    }
};
