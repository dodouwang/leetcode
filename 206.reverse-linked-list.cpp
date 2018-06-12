/*
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (47.25%)
 * Total Accepted:    362.2K
 * Total Submissions: 763.1K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * 
 * Follow up:
 * 
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
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
    // 默认思路是递推过去，需要先思考怎么更改链接，再形成代码
    // 注意都是先把要被覆盖的给找地方存起来，然后可以更改它。
    // 用x更改它之后，又可以继续更改x了。
    ListNode* reverseList1(ListNode* head) {
        if (!head) {
            return head;
        }

        ListNode tmp(0);
        tmp.next = head;
        ListNode *tmpp = &tmp;
        while (head->next) {
            ListNode *cur_part_head = tmpp->next;
            tmpp->next = head->next;
            head->next = head->next->next;
            tmpp->next->next = cur_part_head;
        }
        return tmp.next;
    }
    ListNode* reverseList2(ListNode* head) {
        ListNode* pre = NULL;
        while (head) {
            ListNode* next = head -> next;
            head -> next = pre;
            pre = head;
            head = next;
        } 
        return pre;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
