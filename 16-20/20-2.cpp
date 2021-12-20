#include "../template.hpp"

#define pix(c) (((c) == '#') ? 1 : 0)

int pick(string & alg, map<pii, int> & img, int x, int y) {
    int idx = 0;
    rep(i,-1,2) {
        rep(j,-1,2) {
            idx *= 2;
            idx += img[{x+i,y+j}];
        }
    }
    return pix(alg[idx]);
}

int main() {
    string alg;
    cin >> alg;

    int n, m;

    map<pii, int> image;
    string s;
    int idx = 0;
    while (cin >> s) {
        m = sz(s);
        rep(i,0,sz(s)) {
            image[{idx, i}] = pix(s[i]);
        }
        ++idx;
    }
    n = idx;

    int radius = 150;

    rep(times,0,50) {
        map<pii, int> image_new;

        rep(i,-radius,n+radius) {
            rep(j,-radius,m+radius) {
                image_new[{i,j}] = pick(alg, image, i, j);
            }
        }

        image = image_new;
    }

    int count = 0;
    rep(i,-radius/2,n+radius/2) {
        rep(j,-radius/2,m+radius/2) {
            count += image[{i,j}];
        }
    }

    cout << count;
}

