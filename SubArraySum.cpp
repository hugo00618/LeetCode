//
//  SubArraySum.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-25.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// 1 2 3
// 1 2 3 12 23 123

// n - i
// i*(n-i)

class SubArraySum {
public:
    int subArraySum(vector<int>& arr) {
        int n = arr.size();
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += (i + 1) * (n - i) * arr[i];
        }
        
        return res;
    }
};
