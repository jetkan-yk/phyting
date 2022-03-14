# Kattis - Even Up Solitaire
'''
    Stack with list()
    push(i) -> s.append(i)
    top() -> s[-1]
    pop() -> s.pop()
'''
import sys

n = int(input())
arr = list(map(lambda x: int(x) % 2, sys.stdin.readline().split()))
s = list()

for i in arr:
    if len(s) == 0 or i != s[-1]: s.append(i)
    else: s.pop()

print(len(s))