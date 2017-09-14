//
//  _24.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-14.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include "ListNode.cpp"

using namespace std;

class _24 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode **p1 = &head;
        ListNode *p2, *p3;
        while ((p2 = *p1) && (p3 = p2->next)) {
            p2->next = p3->next;
            p3->next = p2;
            *p1 = p3;
            p1 = &(p3->next);
        }
        
        return head;
    }
};
