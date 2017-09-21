//
//  _49.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-21.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class _49 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> resMap;
        
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            resMap[str].push_back(strs[i]);
        }
        
        vector<vector<string>> res;
        
        for (map<string, vector<string>>::iterator it = resMap.begin(); it != resMap.end(); it++) {
            res.push_back(it->second);
        }
        
        return res;
    }
};
