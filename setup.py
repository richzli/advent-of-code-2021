import sys, os

template = """#include "../template.hpp"

int main() {

}
"""

day = int(sys.argv[1])
fifth = day // 5
folder = f"{fifth*5+1:02}-{(fifth+1)*5:02}"
cookie = open("session").read()
print(cookie)

os.makedirs(folder, exist_ok=True)
os.system(f"curl --cookie \"session={cookie}\" https://adventofcode.com/2021/day/{day}/input > {folder}/{day:02}.in")
open(f"{folder}/{day:02}-1.cpp", "w").write(template)
open(f"{folder}/{day:02}-2.cpp", "w").write(template)