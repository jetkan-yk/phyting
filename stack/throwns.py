# Kattis - Game of Throwns
'''
    Modulo operation, stack
'''
import sys

n, k = map(int, sys.stdin.readline().split())
arr = sys.stdin.readline().split()
ball = i = 0
log = [0]

while i < len(arr):
    if arr[i] == 'undo':
        log = log[:-int(arr[i + 1])]
        ball = log[-1]
        i += 1
    else:
        ball = (ball + int(arr[i])) % n
        log.append(ball)
    i += 1

print(log[-1])