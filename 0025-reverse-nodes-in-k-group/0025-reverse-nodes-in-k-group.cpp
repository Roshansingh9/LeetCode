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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        int count = 0;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* curr1 = head;
        ListNode* forw = NULL;
        int check=0;
        while(curr1!=NULL){
            curr1=curr1->next;;
            check++;
        }
        if (check<k) return head;
        while (curr != NULL && count < k) {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
            count++;
        }
        if (forw != NULL) {
            head->next = reverseKGroup(forw, k);
        }
        return prev;
    }
};