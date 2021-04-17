# Kattis - Integer Lists
'''
    Basic deque operations with lazy reverse
    String operations
'''
import sys
from collections import deque

tc = int(input())

for i in range(tc):
    ops = input()
    n = int(input())
    arr = sys.stdin.readline()
    arr = [] if n == 0 else list(map(int, arr[1:-2].split(',')))

    is_reversed = False
    error = False
    d = deque(arr)
    for op in ops:
        if op == 'R':
            is_reversed = not is_reversed
        elif op == 'D' and d:
            d.pop() if is_reversed else d.popleft()
        else:
            error = True
    if is_reversed: d.reverse()

    if error: print('error')
    else: print('[' + ','.join(str(i) for i in list(d)) + ']')