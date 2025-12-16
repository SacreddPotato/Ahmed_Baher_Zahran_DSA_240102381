#include <string>
#include <iostream>

using namespace std;

string determineQueue(string queue, int t) {
    while (t > 0) {
        for (int i = 0; i < queue.size(); i++) {
            if (i + 1 == queue.size()) {
                break;
            }

            if (queue[i] == 'B') {
                if (queue[i+1] == 'G') {
                    queue[i] = 'G';
                    queue[i+1] = 'B';
                    i++;
                }
            }
        }

        t--;
    }

    return queue;
}

int main() {
    int n;
    int t;
    string queue;

    cin >> n >> t;
    cin >> queue;

    cout << determineQueue(queue, t) << "\n";

    return 0;
}