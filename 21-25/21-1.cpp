#include "../template.hpp"

int main() {
    int p1, p2;
    scanf("Player 1 starting position: %d\n", &p1);
    scanf("Player 2 starting position: %d\n", &p2);
    
    int count = 0;
    int die = 1;
    int score1 = 0, score2 = 0;
    while (score1 < 1000 && score2 < 1000) {
        rep(i,0,3) {
            if (count % 2) {
                p2 += die;
            } else {
                p1 += die;
            }
            ++die;
            die = (die - 1) % 100 + 1;
        }
        p2 = (p2 - 1) % 10 + 1;
        p1 = (p1 - 1) % 10 + 1;
        if (count % 2) {
            score2 += p2;
        } else {
            score1 += p1;
        }

        ++count;

    }

    cout << (count * 3) * min(score1, score2);
}
