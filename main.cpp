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
#include "_21.cpp"

using namespace std;

void printVector(vector<int> ints);

int main(int argc, const char * argv[]) {
    _21 solution = *new _21();
    
    _21::ListNode node1_3 = _21::ListNode(6);
    _21::ListNode node1_2 = _21::ListNode(4);
    node1_2.next = &node1_3;
    _21::ListNode node1_1 = _21::ListNode(2);
    node1_1.next = &node1_2;
    
    _21::ListNode node2_3 = _21::ListNode(5);
    _21::ListNode node2_2 = _21::ListNode(3);
    node2_2.next = &node2_3;
    _21::ListNode node2_1 = _21::ListNode(1);
    node2_1.next = &node2_2;
    
    _21::ListNode *result = solution.mergeTwoLists(&node1_1, &node2_1);
    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
}

void printVector(vector<int> ints) {
    for (int i = 0; i < ints.size(); i++) {
        cout << ints[i] << " ";
    }
    cout << endl;
}
