/*
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (40.29%)
 * Total Accepted:    234.9K
 * Total Submissions: 582.8K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->1->2
 * Output: 1->2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->2->3->3
 * Output: 1->2->3
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
    // 进入时随时可退出，也即肯定和前边不同，或者为null。有cur和pre
    // 若空直接退出。否则往后找，或到其下一个为null，或找到其下一个与现在不同的点，然后处理
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode t(0);
        t.next = head;
        ListNode *cur = head, *pre = &t;
        while (cur) {
            ListNode *incur = cur;
            while (incur->next && incur->next->val == cur->val) {
                incur = incur->next;
            }
            if (incur != cur) { // 当前不止一个，只留一个
                pre->next = incur;
            }
            pre = incur;
            cur = incur->next;
        }
        return t.next;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
