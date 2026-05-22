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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;


        std::vector<ListNode*> nodes;
        while(head){
            nodes.push_back(head); 
            head = head->next;
        } 

        std::vector<ListNode*> orderedNodes;
        int left{},right = nodes.size()-1;
        while(left<=right){
            if(left == right){
                orderedNodes.push_back(nodes[left++]);
            }
            orderedNodes.push_back(nodes[left++]);
            orderedNodes.push_back(nodes[right--]);
        }

        for(int i{};i<orderedNodes.size()-1;i++){
            orderedNodes[i]->next = orderedNodes[i+1];
        }

        orderedNodes.back()->next = nullptr;
        head = orderedNodes[0]; 

    }
};
