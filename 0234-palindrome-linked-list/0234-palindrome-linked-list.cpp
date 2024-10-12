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
    
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = NULL;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(slow != NULL && fast != NULL){
            slow = slow->next;
            if(fast->next != NULL)
                fast = fast->next->next;
            else fast = NULL;
        }
        ListNode* temp = reverse(slow);
        while(head && temp){
            if(head->val != temp->val) return false;
            head = head->next;
            temp = temp->next;
        }
        return true;
    }
};