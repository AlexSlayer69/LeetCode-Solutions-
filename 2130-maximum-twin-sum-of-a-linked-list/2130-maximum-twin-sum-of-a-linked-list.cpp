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
    int pairSum(ListNode* head) {
        vector<int> cheat;
        ListNode* temp = head;
        while(temp){
            cheat.push_back(temp->val);
            temp = temp->next;
        }
        int n = cheat.size();
        int maxi = 0;
        for(int i =0;i<n/2;i++){
            maxi = max(cheat[i]+cheat[n-i-1],maxi);
        }
        return maxi;
    }
};