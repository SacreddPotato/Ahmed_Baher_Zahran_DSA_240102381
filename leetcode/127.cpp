#include <string>
#include <vector>

using namespace std;

class Solution {
    int numOfTransfomrations = 0;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.size() == 0 && beginWord != endWord) {
            return 0;
        }
        
        for (int i = 0; i < wordList.size(); i++) {
            if (beginWord.size() < 2) {
                if (beginWord == wordList.at(i)) {
                    wordList.erase(wordList.begin() + i);
                    return ladderLength(beginWord, endWord, wordList);
                }
                beginWord = wordList.at(i);
                if (beginWord == endWord) {
                    return numOfTransfomrations + 1;
                }
                numOfTransfomrations += 1;
                wordList.erase(wordList.begin() + i);
                return ladderLength(beginWord, endWord, wordList);
            }
            bool helper1 = true;
            bool helper2 = true;
            for (int j = 0; j < beginWord.size(); j++) {
                if (wordList.at(i).at(j) != beginWord.at(j)) {
                    if (helper1) {
                        helper1 = false;
                        continue;
                    }
                    helper2 = false;
                    break;
                }
            }
            if (helper2) {
                beginWord = wordList.at(i);
                if (beginWord == endWord) {
                    return numOfTransfomrations;
                }
                numOfTransfomrations += 1;
                wordList.erase(wordList.begin() + i);
                return ladderLength(beginWord, endWord, wordList);
            }
            wordList.erase(wordList.begin() + i);
            return ladderLength(beginWord, endWord, wordList);
        }
        return numOfTransfomrations;
    }
}; // Unsolved