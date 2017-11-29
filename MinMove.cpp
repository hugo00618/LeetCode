//
//  MinMove.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-25.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class MinMove {
private:
    int minMoves(int a, int b) {
        int res = 0;
        
        while (a > 0) {
            int aDigit = a % 10;
            int bDigit = b % 10;
            res += abs(aDigit - bDigit);
            a /= 10;
            b /= 10;
        }
        
        return res;
    }
    
public:
    int minimumMoves(vector<int> a, vector<int> m) {
        int res = 0;
        
        for (int i = 0; i < a.size(); i++) {
            res += minMoves(a[i], m[i]);
        }
        
        return res;
    }
};
