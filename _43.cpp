//
//  _43.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-20.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

class _43 {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        
        string res(num1.size() + num2.size(), '0');
        
        for (int i = num1.size() - 1; i >= 0; i--) {
            int carryBit = 0;
            int num1Digit = num1[i] - '0';
            for (int j = num2.size() - 1; j >= 0; j--) {
                int product = (res[i + j + 1] - '0') + num1Digit * (num2[j] - '0') + carryBit;
                res[i + j + 1] = product % 10 + '0';
                carryBit = product / 10;
            }
            res[i] = carryBit + '0';
            
            if (carryBit == 0 && i == 0) { // first digit doesn't have carry bit, drop it
                res = res.substr(1);
            }
        }
        
        return res;
    }
};
