#include "../template.hpp"

int x1, x2, y1_, y2, maxt = 0;
set<int> ts;

int simx(int vx) {
    int t = 0, x = 0;
    while (x <= x2 && t <= x2) {
        ++t;
        x += vx;
        if (vx != 0)
            vx -= abs(vx)/vx;

        if (x >= x1) {
            ts.insert(t);
            maxt = max(maxt, t);
        }
    }
    return -1;
}

int main() {
    scanf("target area: x=%d..%d, y=%d..%d", &x1, &x2, &y1_, &y2);

    rep(i,0,x2+1) {
        simx(i);
    }

    int maxy = 0;
    for (int vy = 0; ; ++vy) {
        int y = 0, cvy = vy, cmaxy = 0, t = 0;
        for (; t <= maxt && y > y2; ++t) {
            y += cvy;
            cmaxy = max(y, cmaxy);
            cvy -= 1;
        }

        if (y > y2) {
            break;
        }
        if (y >= y1_ && y <= y2) {
            if (ts.count(t)) {
                maxy = max(maxy, cmaxy);
            }
        }
    }

    cout << maxy;
}
