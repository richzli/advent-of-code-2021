#include "../template.hpp"

struct packet {
    int version;
    int id;
    ll length;
    ll literal;
    vector<struct packet> subpackets;
};
typedef struct packet packet;

string input;
vector<int> bits;
int sum = 0;
int pos = 0;

int read(int len) {
    int ret = 0;
    rep(i,0,len) {
        ret *= 2;
        ret += bits[pos+i];
    }
    pos += len;
    return ret;
}

packet parse() {
    packet pkt;
    pkt.version = read(3);
    sum += pkt.version;
    pkt.id = read(3);
    if (pkt.id == 4) {
        bool notdone = true;
        pkt.literal = 0;
        while (notdone) {
            notdone = read(1);
            pkt.literal *= (1<<4);
            pkt.literal += read(4);
        }
    } else {
        pkt.literal = read(1);
        if (pkt.literal == 0) {
            pkt.length = read(15);
            int currpos = pos;
            while (pos < currpos + pkt.length) {
                pkt.subpackets.pb(parse());
            }
        } else {
            pkt.length = read(11);
            rep(i,0,pkt.length) {
                pkt.subpackets.pb(parse());
            }
        }
    }
    return pkt;
}

int main() {
    cin >> input;
    for (char c : input) {
        int val;
        if ('0' <= c && c <= '9') {
            val = c - '0';
        } else {
            val = c - 'A' + 10;
        }

        for (int i = 3; i >= 0; --i) {
            bits.pb((bool)(val & (1<<i)));
        }
    }

    parse();
    cout << sum;
}
