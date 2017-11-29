//
//  _50.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-21.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>

using namespace std;

class _50 {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        } else if (n < 0) {
            return 1 / myPow(x, -n);
        } else if (n % 2 == 0) {
            return myPow(x * x, n / 2);
        } else {
            return x * myPow(x, n - 1);
        }
    }
};
