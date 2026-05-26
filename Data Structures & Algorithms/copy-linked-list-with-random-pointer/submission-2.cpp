/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = head;
        std::unordered_map<Node*,Node*> oldToNew;


        while(dummy){
            Node* copy = new Node(dummy->val);
            oldToNew[dummy] = copy;
            dummy = dummy->next; 
        }

        dummy = head;
        while(dummy){
            Node* copy = oldToNew[dummy];//didnt know what to do here 
            copy->next = oldToNew[dummy->next];
            copy->random = oldToNew[dummy->random];
            dummy = dummy->next;
        }

        return oldToNew[head];
    }
};
