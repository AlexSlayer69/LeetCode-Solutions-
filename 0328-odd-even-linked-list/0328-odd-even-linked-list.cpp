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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* i = head->next;
        ListNode* prev = head;
        ListNode* border = head;
        int j = 1;
        while(i){
            if(j%2 == 0){
                ListNode* temp = new ListNode(i->val,border->next);
                border->next = temp;
                prev->next = i->next;
                border = border->next;
            }
            j++;
            prev = i;
            i = i->next;
        }
        return head;
    }
};