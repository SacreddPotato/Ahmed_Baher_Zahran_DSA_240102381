#include <string>

using namespace std;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        char helper;
        
        if (s.size() == 1) return s;

        for (int i = 0; i < k && i + 1 < s.size(); i ++) {
            for (int j = i + 1; j < s.size(); j++) {
                if ((int) s.at(i) > (int) s.at(j)) {
                    helper = s[i];
                    s.erase(s.begin() + i);
                    s.push_back(helper);
                    
                    i = -1;
                    break;
                }
            }
        }

        return s;
    }
};

int main() {
    Solution s;

    s.orderlyQueue("cba", 1);

    return 0;
} // Unsolved