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
    void reverse(ListNode*head) {
        ListNode* node = head;
        ListNode* prev = new ListNode();
        while(node) {
            ListNode* nextNode = node->next;
            node->next = prev;
            prev = node;
            node= nextNode;
        }
        head->next = NULL;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        ListNode* ans = new ListNode();
        ans->next = head;
        ListNode* left  = ans;
        int count =  0;
        while(node) {
            count++;
            ListNode* nxt = node->next;
            if(count == k) {
                ListNode* temp = left->next;
                ListNode* curr = node;
                left->next = NULL;
                node->next = NULL;
                reverse(temp);
                temp->next = nxt;
                left->next = curr;
                left = temp;
                count = 0;
            }
            node = nxt;
        }
        return ans->next;
    }
};