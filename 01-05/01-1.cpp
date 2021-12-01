#include "../template.hpp"

int main() {
    int prev, curr, count = 0;
    cin >> prev;
    while (cin >> curr) {
        if (curr > prev) {
            ++count;
        }
        prev = curr;
    } 
    cout << count;
}