//
//  _40.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-19.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class _40 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> res = {};
        vector<int> comb = {};
        combinationSum2(candidates, target, res, comb, 0);
        return res;
    }
private:
    void combinationSum2(vector<int>& candidates, int target,
                         vector<vector<int>>& res, vector<int>& comb, int i) {
        if (target == 0) {
            res.push_back(comb);
            return;
        } else {
            for (int j = i; j < candidates.size() && target - candidates[j] >= 0; j++) {
                comb.push_back(candidates[j]);
                combinationSum2(candidates, target - candidates[j], res, comb, j + 1);
                comb.pop_back();
                
                while (j + 1 < candidates.size() && candidates[j + 1] == candidates[j]) {
                    j++;
                }
            }
        }
    }
};
