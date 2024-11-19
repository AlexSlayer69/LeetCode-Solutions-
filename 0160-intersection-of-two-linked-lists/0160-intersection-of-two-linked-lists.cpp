/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp;
		while(headA){
			temp = headB;
			while(temp){
				if(headA == temp) return headA;
				temp = temp->next;
			}
			headA = headA->next;
		}
		return NULL;
    }
};