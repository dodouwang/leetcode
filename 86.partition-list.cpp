/*
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (33.61%)
 * Total Accepted:    123.1K
 * Total Submissions: 366.2K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * Example:
 * 
 * 
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
        ListNode small(0), big(0);
        ListNode *pre_small = &small, *pre_big = &big;
        while (head) {
            if (head->val < x) {
                pre_small->next = head;
                pre_small = head;
            } else {
                pre_big->next = head;
                pre_big = head;
            }
            head = head->next;
        }
        pre_small->next = big.next;
        pre_big->next = NULL;
        return small.next;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
