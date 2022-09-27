// https://leetcode.com/problems/word-search/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        // if word doesnt exist means nothing to find
        if (!word.size()) return false;
        
        // using 2 loops to get each letter in matrix
        // check if that letter is equal to word[0], means if we could form word from there
        // then we send the word to recursive to check
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (word[0] == board[i][j] && search_word(board, 0, i, j, word)) return true;
            }
        }
        return false;
    }
  
    bool search_word(vector<vector<char>>& board, int index, int i, int j, string &word){
        
        // if the index has surpassed word length and came here
        // means word is formed, as we are checking at each step board[i][j] != word[index]
        // so we return true
        if (index == word.size())
            return true;
        
        // BASE CASE AND WRONG CASE : if the letter is not in word means board[i][j] != word[index]
        // if the index is out of range
        // we return false
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index])
            return false;
        
        // change the current element at i, j so we do not return back to it in other fn calls
        board[i][j] = '0';
            
        // search in all 4 directions, OR of all if even one is true we return true
        bool result = search_word(board, index + 1, i + 1, j, word) || // right
                      search_word(board, index + 1, i, j + 1, word) || // down
                      search_word(board, index + 1, i - 1, j, word) || // left
                      search_word(board, index + 1, i, j - 1, word);   // top
        
        // change back the current element to original
        board[i][j] = word[index];
        
        return result;
    }
};
