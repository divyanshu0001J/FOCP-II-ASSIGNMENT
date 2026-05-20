#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;    //Reading input from STDIN

    char bulbs[100005];
    cin >> bulbs;

    int low = 1, high = n, ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        int operations = 0;

        for (int i = 0; i < n;) {
            if (bulbs[i] == '1') {
                operations++;
                i += mid;
            } else {
                i++;
            }
        }

        if (operations <= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;    // Writing output to STDOUT
}
