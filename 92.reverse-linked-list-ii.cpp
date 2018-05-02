/*
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (31.45%)
 * Total Accepted:    138.7K
 * Total Submissions: 440.7K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) {
            return head;
        }

        ListNode l(0);
        l.next = head;
        ListNode *pp = &l, *p = head, *b, *e, *i = &l, *t;
        int c = 0;
        while (i->next) {
            if (c == m - 1) pp = i;
            i = i->next;
            c++;
            if (c == m) {
                b = i;
                p = i;
                i = i->next;
                break;
            }
        }
        for (int j = m; j < n; ++j) {
            t = i;
            i = i->next;
            t->next = p;
            p = t;
        }
        b->next = i;
        pp->next = p;
        return l.next;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
