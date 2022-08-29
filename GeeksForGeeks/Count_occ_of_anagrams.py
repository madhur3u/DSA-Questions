# https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1#
# https://www.geeksforgeeks.org/anagram-substring-search-search-permutations/

# A simple approach is to traverse from start of the string considering substrings of length equal 
# to the length of the given word and then check if this substring has all the characters of word.     THIS IS NOT DONE HERE, CAN BE DONE WHEN TIME IS NOT ISSUE

def search_anagram(word , text):

    len_word = len(word)                            # taking length of both word and text
    len_text = len(text)        

    word_count = [0]*128                            # store count of all words in word
    text_count = [0]*128                            # this will store count of text in current window only

    count = 0                                   

    for i in range(len_word):                       # 1st we traverse in word to make our word_count which will store count of all words in word

        word_count[ord(word[i])] += 1               # taking ASCII value as index ++ the value at that INDEX
        text_count[ord(text[i])] += 1               # we will also make text_count for current window by same method

# current window, or no. of elements in text_count which will be ++ will always equal to len_word, this is the reason we made our 1st
# array in last for-loop only where we were making word_count, 

    if word_count == text_count :                   # now we will compare both arrays, if equal means anagram is found
        count += 1      

    for i in range(len_word, len_text) :            # this array will fo from len_word till end

        text_count[ord(text[i])] += 1               # ASCII ++ 
        text_count[ord(text[i - len_word])] -= 1    # this will delete the value which is now not needed, as in a window we will compare only len_word elements

        if word_count == text_count :               # if both array equal means anagram found
            count += 1
            
    return count

# main
text = input()                      # text 
word = input()                      # word whose anagrams are to be searched in text
print(search_anagram(word, text))

'''
The idea is to use two count arrays: 
1) The first count array store frequencies of characters in pattern. 
2) The second count array stores frequencies of characters in current window of text.

The important thing to note is, time complexity to compare two count arrays is O(1) as the number of elements in 
them are fixed (independent of pattern and text sizes). 

Following are steps of this algorithm. 
1) Store counts of frequencies of pattern in first count array . 
   Also store counts of frequencies of characters in first window of text in array text_array.
2) Now run a loop from i = M to N-1. Do following in loop. 
…..a) If the two count arrays are identical, we found an occurrence. 
…..b) Increment count of current character of text in countTW[] 
…..c) Decrement count of first character in previous window in countWT[]

'''
