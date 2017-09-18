//
//  _26.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-14.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class _26 {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int count = 1;
        int curNum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == curNum) {
                nums.erase(nums.begin() + i);
                i--;
            } else {
                curNum = nums[i];
                count++;
            }
        }
        return count;
    }
};
