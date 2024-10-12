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

    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val > l2->val) swap(l1, l2);
        ListNode* head = l1;

        while (l1 && l2) {
            ListNode* temp = NULL;
            while (l1 && l1->val <= l2->val) {
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            swap(l1, l2);
        }

        return head;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head; 
        
        ListNode *slow = head, *fast = head, *prev = NULL;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;

        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        
        return merge(left, right);
    }
};
