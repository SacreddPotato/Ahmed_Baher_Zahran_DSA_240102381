#include <string>
#include <vector>

using namespace std;

class WordFilter {
private:
    vector<string> words;
public:
    WordFilter(vector<string>& words) {
        this->words = words;
    }
    
    int f(string pref, string suff) {
        int index = -1;
        for (int k = 0; k < words.size(); k++) {
            for (int i = 0; i < pref.size(); i++) {
                if (words[k][i] != pref[i]) {
                    goto nextWord;
                }
            }

            for (int j = 0; j < suff.size(); j++) {
                if (words[k][words[k].size() - suff.size() + j] != suff[j]) {
                    goto nextWord;
                }
            }

            index = k;
            nextWord:;
        }

        return index;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */