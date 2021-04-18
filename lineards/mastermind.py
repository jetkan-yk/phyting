# Kattis - mastermind
'''
    Use of collections.Counter()
'''
import sys
from collections import Counter

n, code, guess = sys.stdin.readline().split()
n = int(n)
r = s = 0
code_count = Counter()
guess_count = Counter()

for i in range(n):
    if code[i] == guess[i]:
        r += 1
    else:
        code_count[code[i]] += 1
        guess_count[guess[i]] += 1

for letter, count in code_count.items():
    if guess_count[letter] == 0:
        continue
    else:
        s += min(count, guess_count[letter])

print(r, s)