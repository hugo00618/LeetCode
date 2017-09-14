//
//  _23.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-14.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>
#include "ListNode.cpp"

using namespace std;

class _23 {
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode r = ListNode(0);
        ListNode *it = &r;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                it->next = l1;
                l1 = l1->next;
            } else {
                it->next = l2;
                l2 = l2->next;
            }
            it = it->next;
        }
        
        it->next = l1 ? l1 : l2;
        
        return r.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return {};
        } else if (lists.size() == 1) {
            return lists[0];
        } else if (lists.size() == 2) {
            return mergeTwoLists(lists[0], lists[1]);
        } else {
            vector<ListNode*>::iterator mid = lists.begin() + lists.size() / 2;
            vector<ListNode*> left(lists.begin(), mid);
            vector<ListNode*> right(mid, lists.end());
            vector<ListNode*> merged = {mergeKLists(left), mergeKLists(right)};
            return mergeKLists(merged);
        }
    }
};
