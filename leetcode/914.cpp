#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() < 2) {return false;}
        if (deck.size() == 2) {return deck[0] == deck[1];}
        sort(deck.begin(),deck.end());
     
        
        int maxGroupSize = 0;
        for (int i = 0; i < deck.size(); i++) {
            if (deck[i] == 0) {
                continue;
            }

            int count = 1;              
            int j = i + 1;
            while (j < deck.size() && deck[j] == deck[i]) {
                count++;
                j++;
            }

            if (maxGroupSize == 0) {
                maxGroupSize = count;   
            } else if (count != maxGroupSize && ((count % maxGroupSize == 0 || maxGroupSize % count == 0) && (maxGroupSize != 1 && count != 1) || (maxGroupSize % 2 == 0 && count % 2 == 0))) {
                ;
            } else if (count != maxGroupSize) {
                return false;
            }

            i = j - 1; 
        }

        
        return true;
    }
};

int main() {
    Solution s;
    vector<int> deck = {0,0,0,1,1,1,1,1,1,2,2,2,3,3,3};

    s.hasGroupsSizeX(deck);

    return 0;
}