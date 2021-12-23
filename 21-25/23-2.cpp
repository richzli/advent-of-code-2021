#include "../template.hpp"

/* ...try to represent the situation as a graph?
   0123456789a
     b d f h
     c e g i
*/

map<int, vi> g = {
    {0, {1}},
    {1, {0, 2}},
    {2, {1, 3, 11}},
    {3, {2, 4}},
    {4, {3, 5, 15}},
    {5, {4, 6}},
    {6, {5, 7, 19}},
    {7, {6, 8}},
    {8, {7, 9, 23}},
    {9, {8, 10}},
    {10, {9}},

    {11, {2, 12}},
    {12, {11, 13}},
    {13, {12, 14}},
    {14, {13}},

    {15, {4, 16}},
    {16, {15, 17}},
    {17, {16, 18}},
    {18, {17}},

    {19, {6, 20}},
    {20, {19, 21}},
    {21, {20, 22}},
    {22, {21}},

    {23, {8, 24}},
    {24, {23, 25}},
    {25, {24, 26}},
    {26, {25}},
};
vi hallway = {1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
vi room    = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
vi positions = {0, 1, 3, 5, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};

int dist(int a, int b, vi occ) {
    vi dist(27, -1);
    queue<pii> q;
    q.push({a, 0});
    while (!q.empty()) {
        pii cur = q.front(); q.pop();
        if (dist[cur.first] != -1) continue;
        dist[cur.first] = cur.second;
        for (int nxt : g[cur.first]) {
            if (occ[nxt] == 0) q.push({nxt, cur.second+1});
        }
    }
    return dist[b];
}

int valid(int a, int b, vi occ) {
    if (occ[a] == 0) return -1;
    if (room[a] && hallway[b]) {
        int roompos = (a-11)/4 + 1;
        int roombase = (roompos-1)*4 + 11;
        bool ok = true;
        rep(i,a,roombase+4) {
            if (occ[i] != roompos) ok = false;
        }
        if (ok) return -1;
        return dist(a, b, occ);
    }
    if (hallway[a] && room[b]) {
        int roompos = (b-11)/4 + 1;
        int roombase = (roompos-1)*4 + 11;
        if (occ[a] != roompos) return -1;
        int zeros = 0;
        rep(i,0,4) {
            if (occ[roombase + i] != 0) {
                if (occ[roombase + i] != roompos) return -1;
            } else {
                zeros++;
            }
        }
        if (b != roombase + zeros - 1) return -1;
        return dist(a, b, occ);
    }
    return -1;
}

vi finish(27);
map<vi, int> seen;

int play(vi occ) {
    int best = 1000000000;

    if (occ == finish) {
        return 0;
    }
    if (seen[occ] != 0) {
        return seen[occ];
    }

    for (int i : positions) {
        if (occ[i] > 0) {
            for (int j : positions) {
                int cost = pow(10, occ[i]-1);
                cost *= valid(i, j, occ);
                if (cost > 0) {
                    swap(occ[i], occ[j]);
                    best = min(best, play(occ) + cost);
                    swap(occ[j], occ[i]);
                }
            }
        }
    }
    seen[occ] = best;
    return best;
}

int main() {
    char b[17] = "XDDXXCBXXBAXXACX";
    scanf("#############\n#...........#\n###%c#%c#%c#%c###\n  #%c#%c#%c#%c#\n  #########\n", 
        b+0, b+4, b+8, b+12,
        b+3, b+7, b+11, b+15
    );

    vi occupied(27);
    rep(i,0,16) {
        occupied[11+i] = b[i] - 'A' + 1;
        finish[11+i] = i/4 + 1;
    }

    cout << play(occupied);
}
