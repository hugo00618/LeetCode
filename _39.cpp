//
//  _38.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-19.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class _39 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> res = {};
        vector<int> comb = {};
        combinationSum(candidates, target, res, comb, 0);
        return res;
    }
private:
    void combinationSum(vector<int>& candidates, int target,
                        vector<vector<int>>& res, vector<int>& comb, int i) {
        if (target == 0) {
            res.push_back(comb);
            return;
        } else {
            for (int j = i; j < candidates.size() && target - candidates[j] >= 0; j++) {
                comb.push_back(candidates[j]);
                combinationSum(candidates, target - candidates[j], res, comb, j);
                comb.pop_back();
            }
        }
    }
};
