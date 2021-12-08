#include "../template.hpp"

int main() {
    string s;
    int sum = 0;
    while (cin >> s) {
        rep(i,0,10) {
            cin >> s;
        }
        rep (i,0,4) {
            cin >> s;
            switch (s.size()) {
                case 2:
                case 3:
                case 4:
                case 7:
                    ++sum;
                default:
                    break;
            }
        }
    }
    cout << sum;
}
