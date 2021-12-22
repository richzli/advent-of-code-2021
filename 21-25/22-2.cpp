#include "../template.hpp"

int main() {
    char s[5], ch;
    int x1, x2, y1, y2, z1, z2;
    vvi steps;
    set<int> xs, ys, zs;
    while ((ch = getchar()) != EOF) {
        ungetc(ch, stdin);
        scanf("%s x=%d..%d,y=%d..%d,z=%d..%d\n", s, &x1, &x2, &y1, &y2, &z1, &z2);
        steps.pb({strcmp(s, "on") == 0, x1, x2, y1, y2, z1, z2});
        xs.insert(x1); xs.insert(x2+1);
        ys.insert(y1); ys.insert(y2+1);
        zs.insert(z1); zs.insert(z2+1);
    }

    map<int, int> xss, yss, zss;
    int idx = 0;
    for (int x : xs) {
        xss[x] = idx;
        ++idx;
    }
    idx = 0;
    for (int y : ys) {
        yss[y] = idx;
        ++idx;
    }
    idx = 0;
    for (int z : zs) {
        zss[z] = idx;
        ++idx;
    }
    vi xr(all(xs)), yr(all(ys)), zr(all(zs));

    // i really can't be assed to re-write that crap, brute force it is
    vector<vvi> cubes(sz(xs)+1, vvi(sz(ys)+1, vi(sz(zs)+1)));
    for (vi step : steps) {
        rep(i,xss[step[1]],xss[step[2]+1]) {
            rep(j,yss[step[3]],yss[step[4]+1]) {
                rep(k,zss[step[5]],zss[step[6]+1]) {
                    cubes[i][j][k] = step[0];
                }
            }
        }
    }

    ll count = 0;
    rep(i,0,sz(cubes)-1) {
        rep(j,0,sz(cubes[i])-1) {
            rep(k,0,sz(cubes[i][j])-1) {
                if (cubes[i][j][k] > 0) {
                    count += 1LL * (xr[i+1]-xr[i]) * (yr[j+1]-yr[j]) * (zr[k+1]-zr[k]); 
                }
            }
        }
    }
    cout << count;
}
