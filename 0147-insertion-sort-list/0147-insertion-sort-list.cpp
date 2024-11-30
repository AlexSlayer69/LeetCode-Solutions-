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
    void insertIntoSortedList(ListNode* iNode, ListNode* dummy) {
        ListNode* temp = dummy;
        while(temp->next->val < iNode->val) {
            temp = temp->next;
        }
        iNode->next = temp->next;
        temp->next = iNode;
    }

public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-9999);
        dummy->next = head;

        ListNode* lastSorted = head; //last Node of the sorted portion of List
        ListNode* curr = head->next;

        while(curr != NULL) {
            if(curr->val >= lastSorted->val) {
                lastSorted = curr;
                curr = curr->next;
            } else {
                ListNode* nextNode = curr->next;
                lastSorted->next = curr->next;
                curr->next = NULL;
                insertIntoSortedList(curr, dummy);
                curr = nextNode;
            }
        }

        return dummy->next;
    }
};