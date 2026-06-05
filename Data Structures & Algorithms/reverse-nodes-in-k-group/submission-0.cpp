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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        ListNode* curr = &dummy;
        
        std::stack<ListNode*> nodes;
        int count{};
        
        ListNode* hold = head;

        //this works but we dont want to reverse if less then k
        while(head != nullptr){
            nodes.push(head);
            head = head->next;
            count++;
            if(count == k){
                hold = head;
                while(!nodes.empty()){
                    curr->next = nodes.top();
                    nodes.pop();
                    curr = curr->next;
                }
                curr->next = nullptr;
                count = 0;
            }
        }

        if(hold){
            curr->next = hold;
        }
        
        return dummy.next;
        
    }
};
