#include <unordered_map>
struct Node{
    unordered_map<char,Node*> charmap;
    bool end;
    Node():charmap({}),end(false){}
};

class PrefixTree {
public:
    Node* root;
    PrefixTree(){
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(auto c:word){
            if(curr->charmap.find(c) == curr->charmap.end()){
                curr->charmap[c] = new Node();
            }
            curr = curr->charmap[c];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(auto c:word){
            if(curr->charmap.find(c) == curr->charmap.end()){
                return false;
            }
            curr = curr->charmap[c];
        }
        return curr->end;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(auto c:prefix){
            if(curr->charmap.find(c) == curr->charmap.end()){
                return false;
            }
            curr = curr->charmap[c];
        }
        return true;
    }
};
