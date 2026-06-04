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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy;
        

        //loop while there are at least 2 linked list
        while(lists.size() >= 2){
            ListNode* curr = &dummy; 

            //make 2 pointer to both the list we are working on
            ListNode* list1 = lists[0];
            ListNode* list2 = lists[1];


            //loop through list 1 and 2 till we hit a null
            while(list1 && list2){
                //add list1 node to new linked list
                if(list1->val < list2->val){
                    curr->next = list1;
                    list1 = list1->next;
                }
                else{
                    curr->next = list2;
                    list2 = list2->next;
                }
                curr = curr->next;
            }
            
            //if list 1 has any more valid add to the end of dummy
            while(list1){
                curr->next = list1;
                curr = curr->next;
                list1 = list1->next;
            }

            //if list 2 has any more valid add to the end of dummy
            while(list2){
                curr->next = list2;
                curr = curr->next;
                list2 = list2->next;
            }

            curr = &dummy;
            curr = curr->next;
            lists.push_back(curr);
            lists.erase(lists.begin(),lists.begin() + 2);
        }
        return dummy.next; 
    }
};
