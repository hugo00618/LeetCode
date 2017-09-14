//
//  _1.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-07-19.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class _1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> sumMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int myNum = nums.at(i);
            int requiredNum = target - myNum;
            if (sumMap.find(requiredNum) != sumMap.end()) {
                return {sumMap[requiredNum], i};
            }
            sumMap[myNum] = i;
        }
        
        return {};
    }
};
