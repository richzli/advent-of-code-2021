#include "../template.hpp"

typedef struct instruction {
    int a, b, c, i;
} instruction;

int main() {
    stack<instruction> alu;
    vi ans(14);
    rep(i,0,14) {
        instruction ins;
        scanf("inp w\nmul x 0\nadd x z\nmod x 26\ndiv z %d\nadd x %d\neql x w\neql x 0\nmul y 0\nadd y 25\nmul y x\nadd y 1\nmul z y\nmul y 0\nadd y w\nadd y %d\nmul y x\nadd z y\n", &ins.b, &ins.a, &ins.c);
        ins.i = i;
        if (ins.b == 1) {
            alu.push(ins);
        } else {
            instruction ins2 = alu.top(); alu.pop();
            ans[ins2.i] = 9;
            for (;; --ans[ins2.i]) {
                ans[i] = ans[ins2.i] + ins2.c + ins.a;
                if (1 <= ans[i] && ans[i] <= 9) break;
            }
        }
    }

    for (int a : ans) {
        cout << a;
    }
}
