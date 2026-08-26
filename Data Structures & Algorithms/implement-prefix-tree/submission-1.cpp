struct Node{
    unordered_map<char,Node*> next;
    bool end;

    Node():next({}),end(false){}
};

class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        root = new Node();
    }

    
    void insert(string word) {
        Node* curr = root;
        for(auto& c : word){
            if(curr->next.find(c) == curr->next.end()){
                curr->next[c] = new Node;
            }
            curr = curr->next[c];
        } 
        curr->end = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(auto& c : word){
            if(curr->next.find(c) == curr->next.end()){
                return false;
            }
            curr = curr->next[c];
        }
        return curr->end;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(auto& c: prefix){
            if(curr->next.find(c) == curr->next.end()){
                return false; 
            }
            curr = curr->next[c];
        }
        return true;
    }
};
