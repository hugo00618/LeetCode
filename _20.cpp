//
//  _20.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-14.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class _20 {
public:
    bool isValid(string s) {
        stack<char> myStack;
        
        for (char c: s) {
            switch (c) {
                case '(':
                    myStack.push(')');
                    break;
                case '[':
                    myStack.push(']');
                    break;
                case '{':
                    myStack.push('}');
                    break;
                case ')':
                case ']':
                case '}':
                    if (myStack.empty() || myStack.top() != c) {
                        return false;
                    }
                    myStack.pop();
                    break;
            }
        }
        
        return myStack.empty();
    }
};
