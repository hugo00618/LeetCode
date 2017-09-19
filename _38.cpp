//
//  _38.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-19.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class _38 {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        } else {
            string lastCountAndSay = countAndSay(n - 1);
            string result = "";
            
            char lastChar = lastCountAndSay[0];
            int lastCharCount = 1;
            for (int i = 1; i < lastCountAndSay.size(); i++) {
                if (lastCountAndSay[i] == lastChar) {
                    lastCharCount++;
                } else {
                    result += to_string(lastCharCount) + lastChar;
                    
                    lastChar = lastCountAndSay[i];
                    lastCharCount = 1;
                }
            }
            
            result += to_string(lastCharCount) + lastChar;
            
            return result;
        }
    }
};

