/*
 * [160] Intersection of Two Linked Lists
 *
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 *
 * algorithms
 * Easy (30.85%)
 * Total Accepted:    216K
 * Total Submissions: 701.8K
 * Testcase Example:  'No intersection: []\n[]'
 *
 * Write a program to find the node at which the intersection of two singly
 * linked lists begins.
 * 
 * For example, the following two linked lists: 
 * 
 * A:          a1 → a2
 * ⁠                  ↘
 * ⁠                    c1 → c2 → c3
 * ⁠                  ↗            
 * B:     b1 → b2 → b3
 * 
 * begin to intersect at node c1.
 * 
 * Notes:
 * 
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function
 * returns. 
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 * 
 * 
 * 
 * Credits:Special thanks to @stellari for adding this problem and creating all
 * test cases.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;

        ListNode *p1 = headA;
        while (p1->next) {
            p1 = p1->next;
        }
        p1->next = headA;

        ListNode *slow = headB;
        ListNode *fast = headB;
        do {
            if (!fast || !fast->next) break;
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);

        if (!fast || !fast->next) {
            p1->next = NULL;
            return NULL;
        }

        fast = headB;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        p1->next = NULL;
        return slow;
    }
};
