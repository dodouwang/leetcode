/*
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (25.80%)
 * Total Accepted:    157.6K
 * Total Submissions: 611.1K
 * Testcase Example:  '{}'
 *
 * 
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 * 
 * 
 * 
 * Return a deep copy of the list.
 * 
 */
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    // 一遍，然而并不快，还复杂
    RandomListNode *copyRandomList1(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> mp;
        unordered_multimap<RandomListNode*, RandomListNode*> mp_r;
        RandomListNode *t = head;
        RandomListNode *r_tmp = new RandomListNode(0);
        RandomListNode *r_pre = r_tmp;
        while (t) {
            RandomListNode *r = new RandomListNode(t->label);
            mp[t] = r;
            if (t->random) {
                if (mp[t->random] != NULL) {
                    r->random = mp[t->random];
                } else {
                    mp_r.insert(make_pair(t->random, t));
                }
            }

            auto range = mp_r.equal_range(t);
            for (auto i = range.first; i != range.second; i++) {
                mp[i->second]->random = r;
            }

            r_pre->next = r;
            r_pre = r;
            t = t->next;
        }

        t = head;
        while (t) {
            if (t->random) {
                mp[t]->random = mp[t->random];
            }
            t = t->next;
        }

        return r_tmp->next;
    }
    // 两遍，基础打法
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> mp;
        RandomListNode *t = head;
        RandomListNode *r_tmp = new RandomListNode(0);
        RandomListNode *r_pre = r_tmp;
        while (t) {
            RandomListNode *r = new RandomListNode(t->label);
            mp[t] = r;
            r_pre = r_pre->next = r;
            t = t->next;
        }

        t = head;
        while (t) {
            if (t->random) {
                mp[t]->random = mp[t->random];
            }
            t = t->next;
        }

        return r_tmp->next;
    }

};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
