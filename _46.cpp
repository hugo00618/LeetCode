//
//  _46.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-21.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class _46 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()){
            return {};
        } else {
            vector<vector<int>> res = {{nums[0]}};
            for (int i = 1; i < nums.size(); i++) {
                vector<vector<int>> newRes;
                int newNum = nums[i];
                for (vector<int> permutation: res) {
                    // font
                    vector<int> front = permutation;
                    front.insert(front.begin(), newNum);
                    newRes.push_back(front);
                    
                    // end
                    vector<int> end = permutation;
                    end.insert(end.end(), newNum);
                    newRes.push_back(end);
                    
                    // middle
                    for (int j = 1; j < i; j++) {
                        vector<int> middle = permutation;
                        middle.insert(middle.begin() + j, newNum);
                        newRes.push_back(middle);
                    }
                }
                res = newRes;
            }
            return res;
        }
    }
};
