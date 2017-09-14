//
//  _19.cpp
//  LeetCode
//
//  Created by Hugo Yu on 2017-09-14.
//  Copyright © 2017 Hugo Yu. All rights reserved.
//

#include <iostream>
#include <vector>
#include "ListNode.cpp"

using namespace std;

class _19 {
    
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode **t1 = &head;
        ListNode *t2 = head;
        
        for (int i = 0; i < n; i++) {
            t2 = t2->next;
        }
        while (t2 != NULL) {
            t2 = t2->next;
            t1 = (&(*t1)->next);
        }
        *t1 = (*t1)->next;
        
        return head;
    }
};
