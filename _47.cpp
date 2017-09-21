//
//  _47.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-21.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class _47 {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        vector<int> temp, tempIdx;
        
        permuteUnique(res, temp, tempIdx, nums);
        
        return res;
    }
    
    void permuteUnique(vector<vector<int>>& res, vector<int>& temp, vector<int>& tempIdx,
                       vector<int>& nums) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (find(tempIdx.begin(), tempIdx.end(), i) != tempIdx.end()) {
                    continue;
                }
                
                temp.push_back(nums[i]);
                tempIdx.push_back(i);
                permuteUnique(res, temp, tempIdx, nums);
                tempIdx.pop_back();
                temp.pop_back();
                
                while (i < nums.size() && nums[i] == nums[i+1]) {
                    i++;
                }
            }
        }
    }
};
