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
    {4, {3, 5, 13}},
    {5, {4, 6}},
    {6, {5, 7, 15}},
    {7, {6, 8}},
    {8, {7, 9, 17}},
    {9, {8, 10}},
    {10, {9}},
    {11, {2, 12}},
    {12, {11}},
    {13, {4, 14}},
    {14, {13}},
    {15, {6, 16}},
    {16, {15}},
    {17, {8, 18}},
    {18, {17}}
};
vi hallway = {1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
vi room    = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};
vi positions = {0, 1, 3, 5, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};

int dist(int a, int b, vi occ) {
    vi dist(19, -1);
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
        int roompos = (a-11)/2 + 1;
        if ((a % 2 == 0) && occ[a] == roompos) return -1;
        if ((a % 2) && occ[a+1] == roompos && occ[a] == roompos) return -1;
        return dist(a, b, occ);
    }
    if (hallway[a] && room[b]) {
        int roompos = (b-11)/2 + 1;
        if (occ[a] != roompos) return -1;
        if (occ[(roompos-1)*2 + 11] != 0 && occ[(roompos-1)*2 + 11] != roompos) return -1;
        if (occ[(roompos-1)*2 + 12] != 0 && occ[(roompos-1)*2 + 12] != roompos) return -1;
        if (occ[(roompos-1)*2 + 11] == 0 && occ[(roompos-1)*2 + 12] == 0 && (b % 2)) return -1;
        return dist(a, b, occ);
    }
    return -1;
}

vi finish(19);
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
    char b[8];
    scanf("#############\n#...........#\n###%c#%c#%c#%c###\n  #%c#%c#%c#%c#\n  #########\n", 
        b+0, b+2, b+4, b+6,
        b+1, b+3, b+5, b+7
    );

    vi occupied(19);
    rep(i,0,8) {
        occupied[11+i] = b[i] - 'A' + 1;
        finish[11+i] = i/2 + 1;
    }

    cout << play(occupied);
}
