#include "../template.hpp"

int sum(vector<vi> & board) {
    int sum = 0;
    rep(i, 0, 5) {
        rep(j, 0, 5) {
            if (board[i][j] > 0) {
                sum += board[i][j];
            }
        }
    }
    return sum;
}

void mark(vector<vi> & board, int num) {
    rep(i, 0, 5) {
        rep (j, 0, 5) {
            if (board[i][j] == num) {
                board[i][j] *= -1;
                return;
            }
        }
    }
}

bool winner(vector<vi> & board) {
    bool win = true;
    for (int i = 0; i < 5; ++i) {
        win = true;
        for (int j = 0; j < 5; ++j) {
            if (board[i][j] > 0) {
                win = false;
                break;
            }
        }
        if (win) {
            return true;
        }
    }

    for (int i = 0; i < 5; ++i) {
        win = true;
        for (int j = 0; j < 5; ++j) {
            if (board[j][i] > 0) {
                win = false;
                break;
            }
        }
        if (win) {
            return true;
        }
    }

    return false;
}

int main() {
    string nums;
    cin >> nums;
    
    vector<vector<vi>> boards;
    int num;
    while (cin >> num) {
        boards.pb(vector<vi>(5, vi(5)));
        boards.back()[0][0] = num;
        for (int i = 1; i < 25; ++i) {
            cin >> num;
            boards.back()[i / 5][i % 5] = num;
        }
    }

    vi won(boards.size());
    int oldpos = 0;
    int pos = 0;
    int win = 0;
    while ((pos = nums.find(",", oldpos)) != string::npos) {
        int i = stoi(nums.substr(oldpos, pos-oldpos));
        oldpos = pos + 1;

        int idx = 0;
        for (auto & board : boards) {
            mark(board, i);
            if (winner(board) && (won[idx] == 0)) {
                ++win;
                won[idx] = 1;
                if (win == boards.size()) {
                    cout << sum(board) * i;
                }
            }
            ++idx;
        }
    }
}
