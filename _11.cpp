//
//  _11.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-08-25.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class _11 {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int myHeight = min(height[left], height[right]);
            int area = (right - left) * myHeight;
            if (area > maxArea) {
                maxArea = area;
            }
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxArea;
    }

};
