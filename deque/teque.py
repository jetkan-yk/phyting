# Kattis - Teque
'''
    Implement teque with 2 deque, fast I/O
'''
import sys
from collections import deque

TC = int(input())
inputs = sys.stdin.read().splitlines()
outputs = []

d1 = deque()
d2 = deque()
for line in inputs:
    op, x = line.split()
    if op == 'push_back':
        d2.append(x)
    elif op == 'push_front':
        d1.appendleft(x)
    elif op == 'push_middle':
        d2.appendleft(x)
    else:
        idx = int(x)
        result = d1[idx] if idx < len(d1) else d2[idx - len(d1)]
        outputs.append(result)

    if len(d1) < len(d2):
        d1.append(d2.popleft())
    elif len(d1) - 1 > len(d2):
        d2.appendleft(d1.pop())

sys.stdout.write('\n'.join(outputs))