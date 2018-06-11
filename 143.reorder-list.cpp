/*
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (27.06%)
 * Total Accepted:    114.5K
 * Total Submissions: 421.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * Example 1:
 * 
 * 
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 * 
 * Example 2:
 * 
 * 
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return ;
        }
        ListNode *f = head;
        ListNode *s = head;
        while (f->next && f->next->next) {
            s = s->next;
            f = f->next->next;
        }
        ListNode *mid = s;
        ListNode *cur_part_tail = mid->next;
        while (cur_part_tail->next) {
            ListNode *cur_part_head = mid->next;
            mid->next = cur_part_tail->next;
            cur_part_tail->next = cur_part_tail->next->next;
            mid->next->next = cur_part_head;
        }

        ListNode *reverst_head = mid->next;
        mid->next = NULL;
        while (reverst_head) {
            ListNode *head_next = head->next;
            head->next = reverst_head;
            ListNode *reverst_head_next = reverst_head->next;
            reverst_head->next = head_next;
            head = head_next;
            reverst_head = reverst_head_next;
        }

        return ;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
