/*
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (39.07%)
 * Total Accepted:    210.5K
 * Total Submissions: 538.5K
 * Testcase Example:  '[]'
 *
 * 
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * 
 * 
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * 
 * 
 * Your algorithm should use only constant space. You may not modify the values
 * in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        // head是指针，head本身要存放在某个地址上，这个地址的内存上放了head的值，也就是对象的地址。
        // 修改head的值相当于更改head要指向的东西的地址，效果为让head指向别的对象
        // 修改*head的值相当于修改以当前值为地址的那个内存区块的值，就是修改对象的内容

        // pp是指向指针的指针，pp的地址上放了pp的值，也就是head的地址
        // 修改pp的值相当于更改pp要指向的东西的地址，效果为让pp指向别的指针
        // 修改*pp的值相当于修改以当前值为地址的那个内存区块的值，也就是修改了head的值，让head指向别的对象了。
        // 其实考虑修改*pp时，就当是修改head好了。
        // 修改*pp后，再使用head时，head指向的对象就变了，
        ListNode **pp = &head;
        ListNode *a = nullptr;
        ListNode *b = nullptr;

        // 这里pp代表的应该是指向（上一对末尾元素的next）的指针，只有在第一次时是head的内容。
        // 在上一个循环内，已指向原序列的当前循环的开头元素。

        // pp同时起到了两方面作用：
        // 1. pp的值是上一个a->next的地址，也就是原序列的当前循环的开头元素。
        // 2. 修改*pp，还可以在当前循环内修改上一个a->next的值
        while((a = *pp) && (b = a->next))
        {
            a->next = b->next;
            b->next = a;
            // 这里就是把上一个a->next的值给改掉。
            *pp = b;
            // 这里是把当前a->next的地址赋给pp，以备下一次用
            pp = &(a->next);
        }
        return head;
    }
    ListNode* swapPairs1(ListNode* head) {
        ListNode *p = new ListNode(0);
        ListNode *pp = p;
        ListNode *t, *r;
        p->next = head;
        while (head != NULL && head->next != NULL) {
            t = head->next;
            head->next = t->next;
            t->next = head;
            p->next = t;
            p = head;
            head = head->next;
        }
        r = pp->next;
        delete pp;
        return r;
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
