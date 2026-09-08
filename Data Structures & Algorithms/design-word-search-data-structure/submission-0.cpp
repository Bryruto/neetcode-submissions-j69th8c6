struct Node{
    unordered_map<char,Node*> next;
    bool end;

    Node():next({}),end(false){}
}; 

class WordDictionary {
public:
    Node* head; 

    WordDictionary() {
        head = new Node();
    }
    
    void addWord(string word) {
        Node* curr = head;
        for(auto ch : word){
            if(curr->next.find(ch) == curr->next.end()){
                curr->next[ch] = new Node;
            }
            curr = curr->next[ch];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        return dfs(word,0,head);
    }

    bool dfs(string& word, int j, Node* head){
        Node* cur = head;
        for(int i = j;i<word.size();i++){
            char c = word[i];
            if(c == '.'){
                for(auto& [k,v] : cur->next){
                    if (dfs(word,i + 1, v)){
                        return true;
                    }
                }
                return false;
            }
            else{
                if(cur->next.find(c) == cur->next.end()){
                    return false;
                }
                cur = cur->next[c];
            }
        }
        return cur->end;
    }

};
