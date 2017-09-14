//
//  _19.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-14.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class _21 {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    
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
};
