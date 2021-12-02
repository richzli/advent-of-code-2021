#include "../template.hpp"

int main() {
    string dir; int mov;
    int dx = 0, dy = 0;
    while (cin >> dir) {
        cin >> mov;
        if (dir == "forward") {
            dx += mov;
        } else if (dir == "down") {
            dy += mov;
        } else if (dir == "up") {
            dy -= mov;
        }
    }

    cout << dx * dy;
}
