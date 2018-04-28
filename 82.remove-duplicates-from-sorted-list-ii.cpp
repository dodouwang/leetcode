/*
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (30.00%)
 * Total Accepted:    134K
 * Total Submissions: 446.5K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->1->2->3
 * Output: 2->3
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
    // 写循环时,首先要想好进入循环的状态是什么
    // 本次是等待判断当前,还是当前已经ok,准备判断next?
    // 前者需要找到前两个? 后者好一些
    // 当前必不为空,且是第一次出现,每次循环中都找到相等的就一直继续, 直到next为空或不等
    // 然后根据指针是否等于本次头,来判断有几个相等.
    // 然后在根据next是否为空, 来处理
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        ListNode t(0);
        t.next = head;
        ListNode *cur = head, *pre = &t;
        while (true) {
            ListNode *incur = cur;
            while (incur->next && incur->next->val == cur->val) {
                incur = incur->next;
            }
            if (incur == cur) { // 当前只有单个,
                if (incur->next == NULL) { // 没有下个
                    return t.next;
                } else { // 下个和incur不相等了,
                    pre = cur;
                    cur = cur->next;
                }
            } else { // incur != cur, 至少有两个重复了
                if (incur->next == NULL) { // 没下个
                    pre->next = NULL;// 删
                    return t.next;
                } else { // 下个和cur不相等
                    pre->next = incur->next;
                    cur = incur->next;
                }
            }
        }
        return t.next;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
