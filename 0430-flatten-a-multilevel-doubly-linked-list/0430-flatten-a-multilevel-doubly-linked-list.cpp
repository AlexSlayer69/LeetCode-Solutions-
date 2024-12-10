/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node* trav = head;
        vector<Node*> v;
        
        while(trav != NULL)
        {
            if(trav->child != NULL)
            {
               if(trav->next != NULL) v.push_back(trav->next);
                trav->next = trav->child;
                trav->child = NULL;
                trav->next->prev = trav;
                trav = trav->next;
            }
            else
            {
                if(trav->next == NULL && v.size() != 0)
                {
                    trav->next = v[v.size()-1];
                    trav->next->prev = trav;
                    v.pop_back();
                }
                trav = trav->next;
            }
        }
        
        return head;
    }
};