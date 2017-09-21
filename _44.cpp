//
//  _44.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-20.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class _44 {
public:
    bool isMatch(string s, string p) {
        int sIdx = 0, pIdx = 0;
        int lastStarP = -1, lastStarS = -1;
        while (sIdx < s.size()) {
            if (pIdx < p.size() && (p[pIdx] == '?' || s[sIdx] == p[pIdx])) {
                sIdx++;
                pIdx++;
                continue;
            } else if (pIdx < p.size() && p[pIdx] == '*') {
                lastStarP = pIdx;
                lastStarS = sIdx;
                pIdx++;
                continue;
            } else {
                if (lastStarP != -1) {
                    sIdx = lastStarS + 1;
                    lastStarS++;
                    
                    pIdx = lastStarP + 1;
                    continue;
                } else {
                    return false;
                }
            }
        }
        
        for (;pIdx < p.size(); pIdx++) {
            if (p[pIdx] != '*') {
                return false;
            }
        }
        
        return true;
    }
};
