//
//  _12.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-08-25.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class _16 {
    
    
    //    -1, 0, 1, 2, -1, -4
    //    -4, -1, -1, 0, 1, 2
    
    // -1, -1, 2
    // -1, 0, 1
    //
    
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int closest = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < nums.size(); i++) {
            int twoSumTarget = target - nums[i];
            int b = i + 1;
            int c = nums.size() - 1;
            
            while (b < c) {
                int sum = nums[b] + nums[c];
                
                if (sum < twoSumTarget) {
                    b++;
                } else if (sum > twoSumTarget) {
                    c--;
                } else {
                    return target;
                }
                
                int mySum = sum + nums[i];
                if (abs(mySum - target) < abs(closest - target)) {
                    closest = mySum;
                }
            }
        }
        
        return closest;
    }
};
