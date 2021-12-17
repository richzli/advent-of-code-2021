#include "../template.hpp"

int x1, x2, y1_, y2, maxt = 0;
map<int, set<int>> ts;

void simx(int vx) {
    int ovx = vx;
    int t = 0, x = 0;
    while (x <= x2 && t <= x2) {
        ++t;
        x += vx;
        if (vx != 0)
            vx -= abs(vx)/vx;

        if (x >= x1 && x <= x2) {
            ts[t].insert(ovx);
            maxt = max(maxt, t);
        }
    }
}

int main() {
    scanf("target area: x=%d..%d, y=%d..%d", &x1, &x2, &y1_, &y2);

    rep(i,0,x2+1) {
        simx(i);
    }

    int count = 0;
    for (int vy = y1_-1; ; ++vy) {
        int y = 0, cvy = vy, t = 0;
        set<int> tss;
        for (; t <= maxt && y >= y1_; ++t) {
            if (y >= y1_ && y <= y2) {
                tss.insert(all(ts[t]));
            }
            y += cvy;
            cvy -= 1;
        }
        count += sz(tss);

        if (y > y2) {
            break;
        }
    }

    cout << count;
}
