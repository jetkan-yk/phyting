# UVa - 12541 Birthdates
'''
    Custom sort with itemgetter
'''
import sys
from operator import itemgetter

if __name__ == "__main__":
    n = int(input())
    arr = []

    for _ in range(n):
        name, day, month, year = sys.stdin.readline().split()
        arr.append((name, int(day), int(month), int(year)))

    arr.sort(key=itemgetter(3, 2, 1))
    print(arr[n - 1][0])
    print(arr[0][0])
