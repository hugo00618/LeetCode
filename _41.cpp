//
//  _41.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-19.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class _41 {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] - 1 < n && nums[i] >= 1 && nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
    
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return n + 1;
    }
};
