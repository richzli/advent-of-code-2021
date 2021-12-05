import sys, os

day, part = map(int, sys.argv[1:])
fifth = (day-1) // 5
folder = f"{fifth*5+1:02}-{(fifth+1)*5:02}"

os.system(f"runcpp {folder}/{day:02}-{part}.cpp < {folder}/{day:02}.in")