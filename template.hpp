#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int, int> mii;
typedef map<ll, ll> mll;

/* read comma-separated line of ints */
vi rcl() {
    vi nums;
    string s; cin >> s;
    int pos = 0, oldpos = 0;
    int maxx = -1;
    while ((pos = s.find(",", oldpos)) != string::npos) {
        int num = stoi(s.substr(oldpos, pos - oldpos));
        oldpos = pos + 1;
        nums.pb(num);
    }
    nums.pb(stoi(s.substr(oldpos, s.size()-oldpos)));
    return nums;
}