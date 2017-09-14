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

class _18 {
    
//    1, 0, -1, 0, -2, 2
//    -2, -1, 0, 0, 1, 2
    
    // target = 0
    // -2 -1 1 2
    // -2 0 0 2
    // 
    
public:
    vector<vector<int>> threeSum(vector<int>& nums, int target) {
        // sort
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            int twoSumTarget = target - nums[i];
            int b = i + 1;
            int c = nums.size() - 1;
            
            while (b < c) {
                int sum = nums[b] + nums[c];
                
                if (sum < twoSumTarget) {
                    b++;
                } else if (sum == twoSumTarget) {
                    result.push_back({nums[i], nums[b], nums[c]});
                    
                    do {
                        b++;
                    } while (b < c && nums[b] == nums[b - 1]);
                } else { // sum > target
                    c--;
                }
            }
            
            while (i < nums.size() && nums[i+1] == nums[i]) {
                i++;
            }
        }
        
        return result;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result = {};
        for (int i = 0; i < nums.size(); i++) {
            vector<int> myNums(nums.begin()+i+1, nums.end());
            vector<vector<int>> threeSumResult = threeSum(myNums, target - nums[i]);
            for (vector<int> threeSumComb: threeSumResult) {
                threeSumComb.insert(threeSumComb.begin(), nums[i]);
                result.push_back(threeSumComb);
            }
            
            while (i + 1 < nums.size() && nums[i] == nums[i+1]) {
                i++;
            }
        }
        
        return result;
    }
};
