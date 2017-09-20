//
//  _42.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-19.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class _42 {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        int res = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] < maxLeft) {
                    res += maxLeft - height[left];
                } else {
                    maxLeft = height[left];
                }
                left++;
            } else {
                if (height[right] < maxRight) {
                    res += maxRight - height[right];
                } else {
                    maxRight = height[right];
                }
                right--;
            }
        }
        
        return res;
    }
};
