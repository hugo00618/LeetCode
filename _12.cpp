//
//  _12.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-08-25.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>

using namespace std;

class _12 {
public:
    string intToRoman(int num) {
        string roman = "";
        
        for (int i = 0; i < num / 1000; i++) {
            roman += "M";
        }
        num = num % 1000;
        
        for (int i = 0; i < num / 500; i++) {
            roman += "D";
        }
        num = num % 500;
        
        for (int i = 0; i < num / 100; i++) {
            roman += "C";
        }
        num = num % 100;
        
        for (int i = 0; i < num / 50; i++) {
            roman += "L";
        }
        num = num % 50;
        
        for (int i = 0; i < num / 10; i++) {
            roman += "X";
        }
        num = num % 10;
    
        return roman + decToRoman(num);
    }
    
    string decToRoman(int num) {
        switch(num) {
            case 1:
                return "I";
            case 2:
                return "II";
            case 3:
                return "III";
            case 4:
                return "IV";
            case 5:
                return "V";
            case 6:
                return "VI";
            case 7:
                return "VII";
            case 8:
                return "VIII";
            case 9:
                return "IX";
            default:
                return "";
        }
    }
};
