# Kattis - Delimiter Soup
'''
    Bracket matching with stack
'''
import sys

opening = tuple('([{')
closing = tuple(')]}')
expect = dict(zip(opening, closing))

n = int(input())
arr = list(sys.stdin.readline())

i = 0
s = list()
fine = True

for c in arr:
    if c in opening: s.append(expect[c])
    elif c in closing:
        if not s or s.pop() != c:
            print(c, i)
            fine = False
            break
    i += 1

if fine: print('ok so far')