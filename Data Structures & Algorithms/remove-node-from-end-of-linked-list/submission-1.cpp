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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* findsize = head;
        
        int size{};
        while(findsize){
            findsize = findsize->next;
            size++;
        }

        n = size - n;

        if(n == 0) return head->next;
        ListNode* lag = head;
        ListNode* forward = lag->next;

        int count{1};
        for(;count<n;count++){
            lag = forward;
            forward = forward->next;
        }


        lag->next = forward->next;
        return head;
    }
};
