# Kattis - Sort of Sorting
'''
    Multisort with itemgetter/lambda
'''
import sys
from operator import itemgetter

blank = False
while True:
    n = int(input())
    if n == 0: break

    arr = []
    for _ in range(n):
        arr.append(sys.stdin.readline().strip())

    if blank: print()
    print(*sorted(arr, key=itemgetter(0, 1)), sep='\n')
    # print(*sorted(arr, key=lambda x: (x[0], x[1])), sep='\n')
    blank = True