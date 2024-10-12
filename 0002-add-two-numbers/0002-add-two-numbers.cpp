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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(),*prev = new ListNode();
        ans->next = prev;
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            int i = l1->val + l2->val + carry;
            carry = 0;
            if(i >= 10){ 
                carry = 1;
                i %= 10;
            }
            ListNode* node = new ListNode(i);
            prev->next = node;
            prev = node;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            int i = l1->val + carry;
            carry = 0;
            if(i >= 10){ 
                carry = 1;
                i %= 10;
            }
            ListNode* node = new ListNode(i);
            prev->next = node;
            prev = node;
            l1 = l1->next;
        }
        while(l2 != NULL){
            int i = l2->val + carry;
            carry = 0;
            if(i >= 10){ 
                carry = 1;
                i %= 10;
            }
            ListNode* node = new ListNode(i);
            prev->next = node;
            prev = node;
            l2 = l2->next;
        }
        if(carry == 1){
            ListNode* node = new ListNode(1);
            prev->next = node;
            prev = node;
        }
        return ans->next->next;
    }
};