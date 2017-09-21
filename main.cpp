//
//  main.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-07-13.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "ListNode.cpp"
#include "_47.cpp"

using namespace std;

void printVector(vector<int> ints);
void printVector(vector<string> strs);
void printListNode(ListNode* listNode);

int main(int argc, const char * argv[]) {
    _47 solution = *new _47();
    
    vector<int> nums = {1,1,2};
    
    vector<vector<int>> res = solution.permuteUnique(nums);
    
    for (vector<int> permutation: res) {
        printVector(permutation);
    }
}

void printVector(vector<int> ints) {
    for (int i = 0; i < ints.size(); i++) {
        cout << ints[i] << " ";
    }
    cout << endl;
}

void printVector(vector<string> strs) {
    for (int i = 0; i < strs.size(); i++) {
        cout << strs[i] << " ";
    }
    cout << endl;
}

void printListNode(ListNode* listNode) {
    while (listNode != NULL) {
        cout << listNode->val << " ";
        listNode = listNode->next;
    }
    cout << endl;
}
