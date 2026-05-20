#include <iostream>
using namespace std;

long long xorUpTo(long long n) {
    switch (n % 4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long l, r;
    cin >> l >> r;

    long long result = xorUpTo(r) ^ xorUpTo(l - 1);

    cout << (result % 2 == 0 ? "even" : "odd") << "\n";

    return 0;
}
