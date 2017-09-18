//
//  _35.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-15.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class _35 {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        
        return left;
    }
};
