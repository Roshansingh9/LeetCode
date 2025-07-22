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
    void reorderList(ListNode* head) {
          ListNode *slow=head;
          ListNode *fast=head;
          while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
          }
          ListNode *prev=nullptr,*curr=slow,*forward=slow;
          while(curr!=nullptr){
            forward=forward->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
          }
           ListNode* first = head;
        ListNode* second = prev;
        while (second->next) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
          

    }
};