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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> seen;
        for(auto x : nums) seen.insert(x);

        int answer = 0, cnt = 0;
        while(head) {
            if(seen.count(head->val)) cnt++;
            else {
                if(cnt) answer++;
                cnt = 0;
            }
            head = head -> next;
        }
        if(cnt) answer++;
        return answer;
    }
};