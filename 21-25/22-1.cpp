#include "../template.hpp"

int main() {
    vector<vvi> grid(102, vvi(102, vi(102)));
    char s[5], ch;
    int x1, x2, y1, y2, z1, z2;
    int idx = 0;
    while ((ch = getchar()) != EOF) {
        ungetc(ch, stdin);
        scanf("%s x=%d..%d,y=%d..%d,z=%d..%d\n", s, &x1, &x2, &y1, &y2, &z1, &z2);
        if ((x1 > 50) || (x2 < -50) || (y1 > 50) || (y2 < -50) || (z1 > 50) || (z2 < -50)) {
            continue;
        }
        if (strcmp(s, "off") == 0) {
            grid[x1][y1][z1] -= (1<<idx);
            grid[x2][y1][z1] += (1<<idx);
            grid[x1][y2][z1] += (1<<idx);
            grid[x1][y1][z2] += (1<<idx);
            grid[x2][y2][z1] -= (1<<idx);
            grid[x2][y1][z2] -= (1<<idx);
            grid[x1][y2][z2] -= (1<<idx);
            grid[x2][y2][z2] += (1<<idx);
        } else {
            grid[x1][y1][z1] += (1<<idx);
            grid[x2][y1][z1] -= (1<<idx);
            grid[x1][y2][z1] -= (1<<idx);
            grid[x1][y1][z2] -= (1<<idx);
            grid[x2][y2][z1] += (1<<idx);
            grid[x2][y1][z2] += (1<<idx);
            grid[x1][y2][z2] += (1<<idx);
            grid[x2][y2][z2] -= (1<<idx);
        }
        ++idx;
    }

    vector<vvi> cubes(102, vvi(102, vi(102)));
    rep(i,0,102) {
        rep(j,0,102) {
            int cur = 0;
            rep(k,0,102) {
                cur += grid[i][j][k];
                if (j > 0) {
                    cubes[i][j][k] = cubes[i][j-1][k] + cur;
                } else {
                    cubes[i][j][k] = cur;
                }
            }
        }
    }

    rep(j,0,102) {
        rep(k,0,102) {
            rep(i,1,102) {
                cubes[i][j][k] += cubes[i-1][j][k];
            }
        }
    }

    int count = 0;
    rep(i,0,102) {
        rep(j,0,102) {
            rep(k,0,102) {
                if (cubes[i][j][k] > 0) ++count;
            }
        }
    }

    cout << count;
}
