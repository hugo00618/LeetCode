//
//  DeleteSubstring.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-24.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class DeleteSubstring {
public:
    string findRepeat(string& s) {
        for (int i = ceil(s.size() / 2.0); i < s.length(); i++) {
            int length = s.length() - i;
            if (s.substr(0, length) == s.substr(i, length)) {
                return s.substr(0, length);
            }
        }
        return "";
    }
    
    int maxMoves(string s, string t) {
        int res = 0;
    
        vector<int> indices;
        for (int i = 0; i < s.length(); i++) {
            if (s.substr(i, t.length()) == t) {
                indices.push_back(i);
            }
        }
        int offset = 0;
        for (int i = 0; i < indices.size(); i++) {
            if (i + 1 == indices.size() || indices[i] + t.length() <= indices[i+2]) { // no overlap
                s.erase(indices[i] - offset, t.length());
                offset += t.length();
            }
        }
        
        string overlapStr = findRepeat(t);
        int overlapLen = overlapStr.length();
        for (int i = 0; i < s.length(); i++) {
            if (s.substr(i, t.length()) == t) {
                int j = i + 2 * t.length() - overlapLen;
                if (s.substr(j, overlapLen) == overlapStr) {
                    s.erase(i, 2 * s.length() - overlapLen);
                    i--;
                    res += 2;
                }
            }
        }
        
        return res;
    }
};
