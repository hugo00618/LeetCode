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

class _19 {
    
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    
    //    ListNode* removeNthFromEnd(ListNode* head, int n) {
    //        vector<ListNode*> listNodes = {};
    //
    //        ListNode* it = head;
    //        while (it != NULL) {
    //            listNodes.push_back(it);
    //            it = it->next;
    //        }
    //
    //        int removingIdx = listNodes.size() - n;
    //        if (removingIdx == 0) { // removing first node
    //            return head->next;
    //        } else {
    //            ListNode *oneBeforeRemovingNode = listNodes[listNodes.size() - n - 1];
    //            ListNode *removingNode = oneBeforeRemovingNode->next;
    //
    //            oneBeforeRemovingNode->next = removingNode->next;
    //            return head;
    //        }
    //    }
    
    // 1 2 3
    // 2
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
