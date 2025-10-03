class Solution {
public:
    int drunkBottles = 0;
    int emptyBottles = 0;

    int maxBottlesDrunk(int numBottles, int numExchange) {
        if (emptyBottles < numExchange && numBottles == 0) {
            return drunkBottles;
        } else if (emptyBottles >= numExchange) {
            exchangeBottles(numExchange);
            numBottles += 1;
            numExchange += 1;
        } else {
            drink(numBottles);
            numBottles = 0;
        }

        return maxBottlesDrunk(numBottles, numExchange);
    }
    

    void drink(int numBottles) {
        drunkBottles += numBottles;
        emptyBottles += numBottles;
    }

    void exchangeBottles(int numExchange) {
        emptyBottles -= numExchange;
    }
};

// Solved