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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode* temp = head;
        int n = 0;
        while(temp){
            temp = temp->next;
            n++;
        }
        k = k % n; 
        if(k == 0) return head;
        temp = head;
        for(int i = 0;i < n-k-1;i++){
            temp = temp->next;
        }
        ListNode* ans = temp->next;
        temp->next = NULL;
        temp = ans;
        while(temp->next) temp = temp->next;
        temp->next = head;
        return ans;
    }
};