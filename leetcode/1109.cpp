#include <vector>

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> seatsOfIthFlight(n,0);

        for (int i = 0; i < bookings.size(); i++) {
            for (int j = bookings.at(i).at(1); j >= bookings.at(i).at(0); j--) {
                seatsOfIthFlight[j-1] += bookings.at(i).at(2);
            }
        }

        return seatsOfIthFlight;
    } // Solved, But too high of a time complexity, Can't figure out how to reduce it
};