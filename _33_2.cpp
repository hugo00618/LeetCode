//
//  _33_2.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-15.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class _33_2 {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        if (nums[0] == target) {
            return 0;
        }
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == target) {
                return i - 1;
            }
            
            if (nums[i] < nums[i-1]) { // pivot found
                return binarySearch(nums, i, nums.size() - 1, target);
            }
        }
        
        return nums[nums.size() - 1] == target ? nums.size() - 1 : -1;
    }
    
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        if (left > right) {
            return -1;
        }
        
        int mid = (left + right) / 2;
        
        if (nums[mid] < target) {
            return binarySearch(nums, mid + 1, right, target);
        } else if (nums[mid] > target) {
            return binarySearch(nums, left, mid - 1, target);
        } else {
            return mid;
        }
    }
};

// 1 2 3 4 5 6 7

// 6 7 1 2 3 4 5 > 8

//
