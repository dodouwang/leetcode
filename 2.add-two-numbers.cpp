/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (28.54%)
 * Total Accepted:    462.5K
 * Total Submissions: 1.6M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Example
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
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
    // 简单的先用一个多余的头
    // 相当于循环进入状态是当前尾部是上一个节点，需自己新建
    // 结尾时需delete掉
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int added = 0;
        ListNode *head = new ListNode(0);
        ListNode *tail = head;

        while (l1 != NULL || l2 != NULL || added != 0) {
            ListNode *tmp = new ListNode(0);
            tail->next = tmp;
            tail = tmp;

            if (l1 != NULL) {
                tail->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                tail->val += l2->val;
                l2 = l2->next;
            }

            tail->val += added;

            if (tail->val >= 10) {
                added = 1;
                tail->val -= 10;
            } else {
                added = 0;
            }
        }
        tail = head->next;
        delete head;
        return tail;
    }
    // 不用多余的头
    // 相当于每次循环进入时
    // ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
    // }
};
