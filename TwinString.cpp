//
//  TwinString.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-24.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class TwinString {
private:
    bool isTwin(string& s1, string& s2) {
        vector<int> odd (26, 0);
        vector<int> even (26, 0);
        
        for (int j = 0; j < s1.size(); j++) {
            if (j % 2 == 0) {
                even[s1[j] - 'a'] += 1;
                even[s2[j] - 'a'] -= 1;
            } else {
                odd[s1[j] - 'a'] += 1;
                odd[s2[j] - 'a'] -= 1;
            }
        }
        
        for (int i = 0; i < odd.size(); i++) {
            if (odd[i] != 0 || even[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
    
public:
    vector<string> twins(vector<string> a, vector<string> b) {
        vector<string> res;
        
        for (int i = 0; i < a.size(); i++) {
            string ai = a[i];
            string bi = b[i];
            
            if (ai.size() != bi.size()) {
                res.push_back("NO");
            } else {
                if (isTwin(ai, bi)) {
                    res.push_back("YES");
                } else {
                    res.push_back("NO");
                }
            }
        }
        
        return res;
    }
};
