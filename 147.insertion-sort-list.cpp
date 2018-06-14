/*
 * [147] Insertion Sort List
 *
 * https://leetcode.com/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (34.11%)
 * Total Accepted:    121.8K
 * Total Submissions: 356.2K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list using insertion sort.
 * 
 * 
 * 
 * 
 * 
 * A graphical example of insertion sort. The partial sorted list (black)
 * initially contains only the first element in the list.
 * With each iteration one element (red) is removed from the input data and
 * inserted in-place into the sorted list
 * 
 * 
 * 
 * 
 * 
 * Algorithm of Insertion Sort:
 * 
 * 
 * Insertion sort iterates, consuming one input element each repetition, and
 * growing a sorted output list.
 * At each iteration, insertion sort removes one element from the input data,
 * finds the location it belongs within the sorted list, and inserts it
 * there.
 * It repeats until no input elements remain.
 * 
 * 
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode new_head(0);
        ListNode *p_new_head = &new_head;
        p_new_head->next = head;
        ListNode *cur = head->next;
        ListNode *pre_cur = head;
        ListNode *cmp = head;
        ListNode *pre_cmp = p_new_head;
        while (cur) {
            if (cur->val < cmp->val) {
                // 相比2，这里更改了，不能再用head复制，因head可能前面已被插入
                cmp = p_new_head->next;
                pre_cmp = p_new_head;
            }
            while (cmp != cur && cur->val >= cmp->val) {
                pre_cmp = cmp;
                cmp = cmp->next;
            }
            if (cmp != cur) { // cur小于cmp才会进来
                // 相比2，这里更改了，不用再判断pre_cmp不为空
                pre_cmp->next = cur;
                pre_cur->next = cur->next;
                cur->next = cmp;
                pre_cmp = cur;
                cur = pre_cur->next;
            } else {
                pre_cur = cur;
                cur = cur->next;
            }
        }
        return p_new_head->next;
    }
    ListNode* insertionSortList2(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *cur = head->next;
        ListNode *pre_cur = head;
        ListNode *cmp = head;
        ListNode *pre_cmp = NULL;
        while (cur) {
            // 不再从头开始，如果小于上一轮的cmp，才从头开始，否则直接就继续和上一轮的cmp进行比较
            if (cur->val < cmp->val) {
                cmp = head;
                pre_cmp = NULL;
            }
            while (cmp != cur && cur->val >= cmp->val) {
                pre_cmp = cmp;
                cmp = cmp->next;
            }
            if (cmp != cur) { // cur小于cmp才会进来
                // 改前置链接
                if (pre_cmp) pre_cmp->next = cur;
                else head = cur;
                // 跳过cur
                pre_cur->next = cur->next;
                // 改后置链接
                cur->next = cmp;
                // cmp不用改，pre_cmp需要改成cur
                pre_cmp = cur;
                // 下一个，pre_cur不用改
                cur = pre_cur->next;
            } else { // cur位置不需要变化，更新后继续
                pre_cur = cur;
                cur = cur->next;
            }
        }
        return head;
    }    
    // 原始方案
    ListNode* insertionSortList1(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *cur = head->next;
        ListNode *pre_cur = head;
        while (cur) {
            ListNode *cmp = head;
            ListNode *pre_cmp = NULL;
            while (cmp != cur && cur->val > cmp->val) {
                pre_cmp = cmp;
                cmp = cmp->next;
            }
            if (cmp != cur) {
                if (pre_cmp) pre_cmp->next = cur;
                else head = cur;
                pre_cur->next = cur->next;
                cur->next = cmp;
                cur = pre_cur->next;
            } else {
                pre_cur = cur;
                cur = cur->next;
            }
        }
        return head;
    }

};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
