//
//  FirstOccurrance.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-10-05.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>

using namespace std;

class FirstOccurence {
public:
    int firstOccurrence(string s, string x) {
        int i = x.length() - 1;
        
        while (i < s.length()) {
            int j = x.length() - 1;
            
            while (j >= 0) {
                if (x[j] == '*' || s[i] == x[j]) {
                    if (j == 0) { // macthed
                        return i;
                    } else {
                        i--;
                        j--;
                        continue;
                    }
                } else {
                    break;
                }
            }
            
            // bad character
            int badJ;
            for (badJ = j; badJ >= 0; badJ--) {
                if (x[badJ] == '*' || s[i] == x[badJ]) { // bad character found
                    break;
                }
            }
            int badShift = j - badJ + x.length()  - j - 1;
            
            // good suffix
            int goodJ;
            int goodShift = x.length() - 1 - j;
            for (goodJ = j; goodJ >= 0; goodJ--) {
                for (int k = 0; k < x.length() - j - 1; k++) {
                    if (x[goodJ + k] == '*' || x[goodJ + k] == s[i + 1 + k]) {
                        if (k + 1 == x.length() - j - 1) {
                            goodShift += i - goodJ + 1;
                        }
                        continue;
                    } else {
                        break;
                    }
                }
            }
            i += max(badShift, goodShift);
            cout << i << endl;
        }
        
        return -1;
    }
};
