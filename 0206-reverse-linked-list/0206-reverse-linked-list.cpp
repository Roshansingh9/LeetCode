/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *start, *prev, *forward;

        prev = nullptr;
        start = head;
       
        while (start != nullptr) {
             forward = start->next;
            start->next = prev;
            prev = start;
            start = forward;

        }
        return prev;
    }
};