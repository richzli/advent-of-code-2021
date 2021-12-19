#include "../template.hpp"

const int CUTOFF = 12;
typedef vvi matrix;

matrix rotations_1[4] = {
    {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
    {{1, 0, 0}, {0, 0, 1}, {0, -1, 0}},
    {{1, 0, 0}, {0, -1, 0}, {0, 0, -1}},
    {{1, 0, 0}, {0, 0, -1}, {0, 1, 0}}
};

matrix rotations_2[6] = {
    {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
    {{0, 0, -1}, {0, 1, 0}, {1, 0, 0}},
    {{-1, 0, 0}, {0, 1, 0}, {0, 0, -1}},
    {{0, 0, 1}, {0, 1, 0}, {-1, 0, 0}},
    {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}},
    {{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}}
};

matrix mat_mul(matrix A, matrix B) {
    if (sz(A[0]) != sz(B)) {
        return matrix();
    }

    matrix AB = matrix(sz(A), vi(sz(B[0])));
    rep(i,0,sz(A)) {
        rep(j,0,sz(B[0])) {
            rep(k,0,sz(A[0])) {
                AB[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return AB;
}

matrix mat_add(matrix A, matrix B) {
    if ((sz(A) != sz(B)) || (sz(A[0]) != sz(B[0]))) {
        return matrix();
    }

    matrix AB = matrix(sz(A), vi(sz(A[0])));
    rep(i,0,sz(A)) {
        rep(j,0,sz(A[0])) {
            AB[i][j] = A[i][j] + B[i][j];
        }
    }
    return AB;
}

matrix scal_mul(matrix A, int c) {
    rep(i,0,sz(A)) {
        rep(j,0,sz(A[0])) {
            A[i][j] *= c;
        }
    }
    return A;
}

bool eq(matrix A, matrix B) {
    if ((sz(A) != sz(B)) || (sz(A[0]) != sz(B[0]))) {
        return false;
    }

    rep(i,0,sz(A)) {
        rep(j,0,sz(A[0])) {
            if (A[i][j] != B[i][j]) {
                return false;
            }
        }
    }
    return true;
}

matrix T(matrix A) {
    matrix AT = matrix(sz(A[0]), vi(sz(A)));
    rep(i,0,sz(A)) {
        rep(j,0,sz(A[0])) {
            AT[j][i] = A[i][j];
        }
    }
    return AT;
}

vi rcl_ss(stringstream ss) {
    vi nums;
    string s; ss >> s;
    size_t pos = 0, oldpos = 0;
    while ((pos = s.find(",", oldpos)) != string::npos) {
        int num = stoi(s.substr(oldpos, pos - oldpos));
        oldpos = pos + 1;
        nums.pb(num);
    }
    nums.pb(stoi(s.substr(oldpos, s.size()-oldpos)));
    return nums;
}

void print_point(matrix p) {
    cout << p[0][0] << "," << p[1][0] << "," << p[2][0] << endl;
}

typedef struct scanner {
    int rot_1 = 0, rot_2 = 0;
    int dx = 0, dy = 0, dz = 0;
    bool fixed = false, exhausted = false;
    vector<matrix> points;
} scanner;

scanner transform(scanner sc) {
    scanner ret;
    for (matrix p : sc.points) {
        matrix p2 = mat_mul(rotations_1[sc.rot_1], mat_mul(rotations_2[sc.rot_2], p));
        p2[0][0] -= sc.dx;
        p2[1][0] -= sc.dy;
        p2[2][0] -= sc.dz;
        ret.points.pb(p2);
    }
    return ret;
}

pair<bool, scanner> compare(scanner sc1, scanner sc2) {
    rep(i,0,4) {
        rep(j,0,6) {
            sc2.rot_1 = i;
            sc2.rot_2 = j;
            scanner sc2_new = transform(sc2);

            // build complete graphs of the two scanners
            vector<set<matrix>> g1(sz(sc1.points), set<matrix>()),
                                g2(sz(sc2_new.points), set<matrix>());
            rep(ii,0,sz(sc1.points)) {
                rep(jj,0,sz(sc1.points)) {
                    g1[ii].insert(mat_add(sc1.points[ii], scal_mul(sc1.points[jj], -1)));
                }
            }
            rep(ii,0,sz(sc2.points)) {
                rep(jj,0,sz(sc2.points)) {
                    g2[ii].insert(mat_add(sc2_new.points[ii], scal_mul(sc2_new.points[jj], -1)));
                }
            }

            // build a mapping between points
            int idx1 = -1, idx2 = -1;
            rep(ii,0,sz(g1)) {
                if (idx1 != -1) break;

                rep(jj,0,sz(g2)) {

                    int matches = 0;
                    // check if these two points have 12 matching distance deltas
                    for (matrix p : g1[ii]) {
                        if (g2[jj].count(p)) {
                            ++matches;
                        }
                    }

                    if (matches >= CUTOFF) {
                        idx1 = ii;
                        idx2 = jj;
                        break;
                    }

                }
            }

            if (idx1 != -1) {
                sc2_new.dx = sc2_new.points[idx2][0][0] - sc1.points[idx1][0][0];
                sc2_new.dy = sc2_new.points[idx2][1][0] - sc1.points[idx1][1][0];
                sc2_new.dz = sc2_new.points[idx2][2][0] - sc1.points[idx1][2][0];
                sc2_new = transform(sc2_new);
                return {true, sc2_new};
            }
        }
    }

    return {false, sc2};
}

int main() {
    vector<scanner> scanners;
    scanner cur;
    string s;
    getline(cin, s);
    while (getline(cin, s)) {
        if (s == "") {
            scanners.pb(cur);
            cur = scanner();
            getline(cin, s);
            continue;
        }

        cur.points.pb(T({rcl_ss(stringstream(s))}));
    }
    if (sz(cur.points)) scanners.pb(cur);
    scanners[0].fixed = true;

    bool done = false;
    while (!done) {
        done = true;

        rep(i,0,sz(scanners)) {
            if (scanners[i].fixed && !scanners[i].exhausted) {
                rep(j,0,sz(scanners)) {
                    if (!scanners[j].fixed) {
                        cout << "comparing scanner " << i << " to scanner " << j << endl;
                        auto ret = compare(scanners[i], scanners[j]);
                        if (ret.first) {
                            cout << "they match!" << endl;
                            scanners[j] = ret.second;
                            scanners[j].fixed = true;
                        }
                    }
                }
                scanners[i].exhausted = true;
            } else if (!scanners[i].fixed) {
                done = false;
                cout << "scanner " << i << " is not done" << endl;
            }
        }
    }

    set<matrix> points;
    for (scanner sc : scanners) {
        for (matrix p : sc.points) {
            points.insert(p);
        }
    }

    cout << sz(points);
}
