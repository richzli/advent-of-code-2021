#include "../template.hpp"

#define mod1(n, m) (((n)-1)%(m)+1)

int main() {
    int p1, p2;
    scanf("Player 1 starting position: %d\n", &p1);
    scanf("Player 2 starting position: %d\n", &p2);

    ll dp[31][11][31][11][2];
    memset(dp, 0, sizeof(dp));
    dp[0][p1][0][p2][0] = 1;

    vl transition(10);
    rep(i,1,4) {
        rep(j,1,4) {
            rep(k,1,4) {
                transition[i+j+k]++;
            }
        }
    }

    rep(i,0,21) {
        rep(j,0,21) {
            rep(k,0,11) {
                rep(l,0,11) {
                    rep(m,0,2) {
                        if (dp[i][k][j][l][m] > 0) {
                            rep(n,0,10) {
                                if (m == 0) {
                                    dp[i+mod1(k+n,10)][mod1(k+n,10)][j][l][1] += dp[i][k][j][l][0] * transition[n];
                                } else {
                                    dp[i][k][j+mod1(l+n,10)][mod1(l+n,10)][0] += dp[i][k][j][l][1] * transition[n];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    ll win1 = 0, win2 = 0;
    rep(i,0,31) {
        rep(j,0,31) {
            if (i < 21 && j < 21) {
                continue;
            }

            rep(k,0,11) {
                rep(l,0,11) {
                    rep(m,0,2) {
                        if (i > j) {
                            win1 += dp[i][k][j][l][m];
                        } else {
                            win2 += dp[i][k][j][l][m];
                        }
                    }
                }
            }
        }
    }

    cout << max(win1, win2);
}
