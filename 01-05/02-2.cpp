#include "../template.hpp"

int main() {
    string dir; int mov;
    int dx = 0, dy = 0, aim = 0;
    while (cin >> dir) {
        cin >> mov;
        if (dir == "forward") {
            dx += mov;
            dy += mov * aim;
        } else if (dir == "down") {
            aim += mov;
        } else if (dir == "up") {
            aim -= mov;
        }
    }

    cout << dx * dy;
}
