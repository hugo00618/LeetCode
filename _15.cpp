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

class _15 {
    
    
    //    -1, 0, 1, 2, -1, -4
    //    -4, -1, -1, 0, 1, 2
    
    // -1, -1, 2
    // -1, 0, 1
    //
    
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int b = i + 1;
            int c = nums.size() - 1;
            
            while (b < c) {
                int sum = nums[b] + nums[c];
                
                if (sum < target) {
                    b++;
                } else if (sum == target) {
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
};
