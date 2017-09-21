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
#include "_48.cpp"

using namespace std;

void printVector(vector<int> ints);
void printVector(vector<string> strs);
void printListNode(ListNode* listNode);

int main(int argc, const char * argv[]) {
    _48 solution = *new _48();
    
    vector<vector<int>> nums = {{5, 1, 9,11},{2, 4, 8,10},{13, 3, 6, 7},{15,14,12,16}};
    
    solution.rotate(nums);
    
    for (vector<int> permutation: nums) {
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
