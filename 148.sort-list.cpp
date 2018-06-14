/*
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (30.29%)
 * Total Accepted:    137K
 * Total Submissions: 449.6K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *p1 = head;
        ListNode *p2 = slow->next;
        slow->next = NULL;
        p1 = sortList(p1);
        p2 = sortList(p2);
        ListNode new_head(0);
        ListNode *p_new_head = &new_head;
        p_new_head->next = p1;
        ListNode *c1 = p1;
        ListNode *c2 = p2;
        ListNode *c1_pre = p_new_head;
        while (c1 && c2) {
            if (c2->val < c1->val) {
                c1_pre->next = c2;
                ListNode *c2_next = c2->next;
                c2->next = c1;
                c1_pre = c2;
                c2 = c2_next;
            } else {
                c1_pre = c1;
                c1 = c1->next;
            }
        }

        if (c2) {
            c1_pre->next = c2;
        }
        return p_new_head->next;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
