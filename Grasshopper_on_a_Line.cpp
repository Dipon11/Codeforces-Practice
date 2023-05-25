#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    if (t < 1 || t > 3) {
        cout << "Invalid number of test cases. The number of test cases should be between 1 and 3." << endl;
        return 0;
    }

    while (t--) {
        int x, k;
        cin >> x >> k;

        if (x % k == 0) {
            cout << -1 << endl;
        } else {
            int moves = (x / k) + 1;
            int remaining = x % k;

            cout << moves << endl;
            for (int i = 0; i < moves - 1; i++) {
                cout << k << " ";
            }
            cout << remaining << endl;
        }
    }

    return 0;
}
