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
    ListNode* merge_sort(ListNode* list1, ListNode* list2) {
        ListNode* start = new ListNode(0);
        ListNode* dummy = start;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                dummy->next = list1;
                list1 = list1->next;
            } else {
                dummy->next = list2;
                list2 = list2->next;
            }
            dummy = dummy->next;
        }
        if (list1 != nullptr)
            dummy->next = list1;
        else
            dummy->next = list2;
        return start->next;
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        if (list1->val < list2->val) {
            return merge_sort(list1, list2);
        } else {
            return merge_sort(list2, list1);
        }
    }
};