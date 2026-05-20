#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;    

    while (num--) {
        int n;
        cin >> n;

        int x = n;
        int c = 0;

        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                c++;
                while (x % i == 0) {
                    x = x / i;
                }
            }
        }

        if (x > 1) {
            c++;
        }

        int ans = 1;
        for (int i = 0; i < c; i++) {
            ans = ans * 2;
        }

        cout << ans << endl;
    }
}
