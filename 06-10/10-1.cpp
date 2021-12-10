#include "../template.hpp"

int main() {
    string s;
    int sum = 0;
    while (cin >> s) {
        stack<char> stk;
        bool fail = false;
        for (char c : s) {
            switch (c) {
                case '{':
                case '[':
                case '(':
                case '<':
                    stk.push(c);
                    break;
                default:
                    if (!stk.empty()) {
                        switch (c) {
                            case ')':
                                if (stk.top() != '(') fail = true;
                                break;
                            case ']':
                                if (stk.top() != '[') fail = true;
                                break;
                            case '}':
                                if (stk.top() != '{') fail = true;
                                break;
                            case '>':
                                if (stk.top() != '<') fail = true;
                                break;
                        }
                        stk.pop();
                    }
                    if (!fail) { break; }
                    switch (c) {
                        case ')':
                            sum += 3;
                            break;
                        case ']':
                            sum += 57;
                            break;
                        case '}':
                            sum += 1197;
                            break;
                        case '>':
                            sum += 25137;
                            break;
                    }
            }
            if (fail) break;
        }
    }

    cout << sum;
}
