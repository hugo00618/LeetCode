//
//  _31.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-07-25.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class _31 {
public:
    void nextPermutation(vector<int>& nums) {
        // find left target idx
        int leftTarget = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                leftTarget = i;
                break;
            }
        }
        
        // nums is in descending order, no next permutation, sort the whole list to get minimum
        if (leftTarget == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
    
        // find right target idx
        int rightTarget = 0;
        for (int i = leftTarget + 1; i < nums.size(); i++) {
            if (nums[i] > nums[leftTarget]) {
                rightTarget = i;
            }
        }
    
        // swap left and right
        swap(nums[leftTarget], nums[rightTarget]);
        
        // reverse right part
        reverse(nums.begin() + leftTarget + 1, nums.end());
    }
};
