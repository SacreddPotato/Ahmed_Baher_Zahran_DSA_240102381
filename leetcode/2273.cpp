#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int left = 0;
        vector<string> copy = words;
        set<int> leftWord;
        set<int> rightWord;

        for (int i = 0; i < words.size(); i++) {
            if (i == left) {continue;}

            for (char c: words.at(left)) {
                leftWord.insert((int) c);
            }

            for (char c: words.at(i)) {
                rightWord.insert((int) c);
            }

            if (leftWord == rightWord) {
                copy.erase(copy.end() + left + 1);
                rightWord.clear();
            } else {
                left+=1;
                i = left + 1; 
                leftWord.clear();
                rightWord.clear();
            }
        }

        return copy;
    }
};

int main() {
    Solution s;
    vector<string> data = {"abba","baba","bbaa","cd","cd"};
    s.removeAnagrams(data);

    return 0;
}