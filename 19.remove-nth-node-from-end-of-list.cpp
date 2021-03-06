/*
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (33.99%)
 * Total Accepted:    240.1K
 * Total Submissions: 706.2K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the nth node from the end of list and return its
 * head.
 * 
 * For example,
 * 
 * 
 * ⁠  Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * ⁠  After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        ListNode *pre = head;
        while (n > 0) {
            p = p->next;
            n--;
        }
        if (p == NULL) {
            return head->next;
        }

        while (p->next != NULL) {
            p = p->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
