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
private:
    ListNode* helper(ListNode* head) {
        ListNode* last = head->next;
        ListNode* second_last = head;
        while (last->next != nullptr) {
            last = last->next;
            second_last = second_last->next;
        }
        second_last->next = nullptr;
        last->next = head;
        return last;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        ListNode* temp = head;
        int length = 1;
        while (temp->next != nullptr) {
            length += 1;
            temp = temp->next;
        }
        k = k % length;
        if (k == 0)
            return head;
        temp = head;

        for (int i = 0; i < k; i++) {
            temp = helper(temp);
        }
        return temp;
    }
};