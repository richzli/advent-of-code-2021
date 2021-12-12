#include "../template.hpp"

map<string, bool> small;
map<string, vector<string>> g;
int counter = 0;

map<string, bool> visited;

bool isupper(string s) {
    for (char c : s) {
        if (c < 'A' || c > 'Z') {
            return false;
        }
    }
    return true;
}

void dfs(string room) {
    if (room == "end") {
        ++counter;
        return;
    }

    visited[room] = true;

    for (string nxt : g[room]) {
        if (small[nxt]) {
            if (!visited[nxt]) {
                dfs(nxt);
            }
        } else {
            dfs(nxt);
        }
    }

    visited[room] = false;
}

int main() {
    string s;
    while (cin >> s) {
        int pos = s.find("-");
        string u = s.substr(0, pos);
        string v = s.substr(pos+1, sz(s)-(pos+1));

        if (!isupper(u)) {
            small[u] = true;
        }
        if (!isupper(v)) {
            small[v] = true;
        }

        g[u].pb(v);
        g[v].pb(u);
        visited[u] = false;
        visited[v] = false;
    }

    dfs("start");
    cout << counter;
}
