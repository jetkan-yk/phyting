# Kattis - Card Trick
'''
    Pre-calculate the answer (cardtrick.py)
    Simulation with Queue
    O(N^3) pre-calculation, O(1) solution
    
    Use this program to generate answer for cardtrick2.py
'''
from collections import deque
import sys

ans = []  # 0-indexed

for n in range(14):
    q = deque([n])
    for step in range(n - 1, 0, -1):
        q.appendleft(step)
        for _ in range(step):
            q.appendleft(q.pop())
    ans.append(list(q))

print(ans)