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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
         if (!head) return NULL;
        ListNode* temp = new ListNode(-1);
        temp->next = head;
        ListNode* prev = temp;
        
        for (int i = 1; i < left; i++) prev = prev->next;

        ListNode* curr = prev->next;
        ListNode* nxt = curr->next;
    
        for (int i = 0; i < right - left; i++) {
            curr->next = nxt->next;
            nxt->next = prev->next;
            prev->next = nxt;
            nxt = curr->next;
        }

        return temp->next;
    }
};