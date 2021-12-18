#include "../template.hpp"

typedef struct snailfish {
    int literal = -1;
    snailfish * left = NULL;
    snailfish * right = NULL;
    snailfish * parent = NULL;
} snailfish;

string s;
int pos;

snailfish * parse() {
    snailfish * sf = new snailfish();
    if ('0' <= s[pos] && s[pos] <= '9') {
        sf->literal = s[pos] - '0';
        ++pos;
    } else {
        ++pos; // [
        sf->left = parse();
        sf->left->parent = sf;
        ++pos; // ,
        sf->right = parse();
        sf->right->parent = sf;
        ++pos; // ]
    }
    return sf;
}

void print(snailfish * sf) {
    if (sf->literal != -1) {
        cout << sf->literal;
    } else {
        cout << '[';
        print(sf->left);
        cout << ',';
        print(sf->right);
        cout << ']';
    }
}

ll magnitude(snailfish * sf) {
    if (sf->literal != -1) {
        return sf->literal;
    } else {
        return 3 * magnitude(sf->left) + 2 * magnitude(sf->right);
    }
}

snailfish * copy(snailfish * sf) {
    snailfish * ret = new snailfish();
    if (sf->literal != -1) {
        ret->literal = sf->literal;
    } else {
        ret->left = copy(sf->left);
        ret->right = copy(sf->right);
    }
    return ret;
}

snailfish * cur;

snailfish * last_literal = NULL;
int add_to_next = -1;
bool explode(snailfish * sf, int depth) {
    if (add_to_next == -2) return true;

    if (depth >= 4 && sf->literal == -1 && add_to_next == -1 && sf->left->literal != -1 && sf->right->literal != -1) {
        if (last_literal != NULL) {
            last_literal->literal += sf->left->literal;
        }
        add_to_next = sf->right->literal;
        delete sf->left;
        delete sf->right;
        sf->literal = 0;
        last_literal = sf;
        return true;
    }

    if (sf->literal != -1) {
        if (add_to_next != -1) {
            sf->literal += add_to_next;
            add_to_next = -2;
            return true;
        }
        last_literal = sf;
        return false;
    } else {
        int ret = false;
        ret |= explode(sf->left, depth + 1);
        ret |= explode(sf->right, depth + 1);
        return ret;
    }
}

bool split(snailfish * sf) {
    if (sf->literal >= 10) {
        sf->left = new snailfish();
        sf->left->literal = sf->literal/2;
        sf->right = new snailfish();
        sf->right->literal = sf->literal - sf->left->literal;
        sf->literal = -1;
        return true;
    } else if (sf->literal == -1) {
        if (split(sf->left)) return true;
        if (split(sf->right)) return true;
    }
    return false;
}

bool reduce() {
    last_literal = NULL;
    add_to_next = -1;
    if (explode(cur, 0)) return true;
    if (split(cur)) return true;
    return false;
}

int main() {
    vector<snailfish *> numbers;
    while (cin >> s) {
        pos = 0;
        snailfish * num = parse();
        numbers.pb(num);
    }
    ll mx = 0;
    rep(i,0,sz(numbers)) {
        rep(j,0,sz(numbers)) {
            if (i != j) {
                cur = new snailfish();
                cur->left = copy(numbers[i]);
                cur->right = copy(numbers[j]);
                while (reduce());
                mx = max(mx, magnitude(cur));
            }
        }
    }
    cout << mx;
}
