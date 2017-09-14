//
//  _33.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-07-17.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class _33 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findEndPoint(true, nums, target, 0, nums.size()-1),
            findEndPoint(false, nums, target, 0, nums.size()-1)};
    }
    
    int findEndPoint(bool leftEndpoint, vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return -1;
        }
        
        int mid = (left + right) / 2;
        int midNum = nums.at(mid);
        
        if (midNum == target) {
            if (leftEndpoint) {
                if (mid - 1 < 0) { // left boundary reached
                    return mid;
                } else {
                    int oneBeforeMidNum = nums.at(mid - 1);
                    if (oneBeforeMidNum != target) { // left endpoint found
                        return mid;
                    } else {
                        return findEndPoint(leftEndpoint, nums, target, left, mid - 1);
                    }
                }
            } else {
                if (mid + 1 == nums.size()) { // right boundary reached
                    return mid;
                } else {
                    int oneAfterMidNum = nums.at(mid + 1);
                    if (oneAfterMidNum != target) { // right end point found
                        return mid;
                    } else {
                        return findEndPoint(leftEndpoint, nums, target, mid + 1, right);
                    }
                }
             }
        } else if (midNum > target) {
            return findEndPoint(leftEndpoint, nums, target, left, mid - 1);
        } else { // midNum < target
            return findEndPoint(leftEndpoint, nums, target, mid + 1, right);
        }
    }
};
