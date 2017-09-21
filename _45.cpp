//
//  _45.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-20.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class _45 {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        } else {
            int steps = 1;
            int i = 0;
            while (i + nums[i] < n - 1) {
                steps++;
                int maxStep = 0, maxStepIdx = 0;
                for (int j = i + 1; j < i + nums[i] + 1; j++) {
                    if (nums[j] + j > maxStep) {
                        maxStep = nums[j] + j;
                        maxStepIdx = j;
                    }
                }
                i = maxStepIdx;
            }
            return steps;
        }
    }
};
