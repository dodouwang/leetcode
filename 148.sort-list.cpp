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
        // 然后开始merge
        p1 = sortList(p1);
        p2 = sortList(p2);
        ListNode new_head(0);
        ListNode *p_new_head = &new_head;
        // 下方两行建立p_pre和p1的前后关系
        p_new_head->next = p1;
        ListNode *p1_pre = p_new_head;
        while (p1 && p2) {
            if (p2->val < p1->val) {
                p1_pre->next = p2;
                ListNode *p2_next = p2->next;
                // 下方两行更新p2作为p1_pre的前后关系
                p2->next = p1;
                p1_pre = p2;
                p2 = p2_next;
            } else {
                p1_pre = p1;
                p1 = p1->next;
            }
        }
        if (p2) {
            p1_pre->next = p2;
        }
        return p_new_head->next;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
