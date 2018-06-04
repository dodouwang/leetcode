/*
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (30.45%)
 * Total Accepted:    150.9K
 * Total Submissions: 495.9K
 * Testcase Example:  '[]\nno cycle'
 *
 * 
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 * 
 * 
 * 
 * Note: Do not modify the linked list.
 * 
 * 
 * Follow up:
 * Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
        if (!head) {
            return NULL;
        }

        ListNode *quick = head;
        ListNode *slow = head;
        while (quick->next != NULL && quick->next->next != NULL && slow->next != NULL) {
            quick = quick->next->next;
            slow = slow->next;
            if (quick == slow) {
                ListNode *prev = head;
                quick = quick->next;
                prev = prev->next;
                while (quick != slow) {
                    quick = quick->next;
                    prev = prev->next;
                }
                while (prev != head) {
                    prev = prev->next;
                    head = head->next;
                }
                return prev;
            }
        }
        return NULL;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
