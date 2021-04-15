# UVa - 10107 What is the Median?
'''
    Use of bisect.insort() and statistics.median()
'''
import sys
from bisect import insort
from statistics import median

arr = []

for n in sys.stdin.readlines():
    insort(arr, int(n))
    print(int(median(arr)))