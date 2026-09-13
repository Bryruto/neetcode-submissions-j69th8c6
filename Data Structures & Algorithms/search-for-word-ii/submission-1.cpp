class Solution {
    struct TrieNode {
        TrieNode* children[26] = {};
        string word = "";
    };

    void insert(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->word = word;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& w : words) {
            insert(root, w);
        }

        vector<string> result;
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[r].size(); c++) {
                dfs(r, c, root, board, result);
            }
        }
        return result;
    }

    void dfs(int r, int c, TrieNode* curr, vector<vector<char>>& board, vector<string>& result) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == '*')
            return;

        char ch = board[r][c];
        int idx = ch - 'a';
        if (!curr->children[idx])
            return;

        curr = curr->children[idx];
        if (!curr->word.empty()) {
            result.push_back(curr->word);
            curr->word = ""; // avoid duplicate results
        }

        board[r][c] = '*';
        dfs(r, c - 1, curr, board, result);
        dfs(r, c + 1, curr, board, result);
        dfs(r - 1, c, curr, board, result);
        dfs(r + 1, c, curr, board, result);
        board[r][c] = ch;
    }
};