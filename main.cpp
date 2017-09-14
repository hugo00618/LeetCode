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
#include "_24.cpp"

using namespace std;

void printVector(vector<int> ints);
void printVector(vector<string> strs);
void printListNode(ListNode* listNode);

int main(int argc, const char * argv[]) {
    _24 solution = *new _24();
    
    ListNode node4 = ListNode(4);
    ListNode node3 = ListNode(3);
    node3.next = &node4;
    ListNode node2 = ListNode(2);
    node2.next = &node3;
    ListNode node1 = ListNode(1);
    node1.next = &node2;
    
    ListNode* result = solution.swapPairs(&node1);
//    cout << result->val << endl;
//    cout << result->next->val << endl;
//    cout << result->next->next->val << endl;
    printListNode(result);
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
